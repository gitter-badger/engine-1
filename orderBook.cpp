#include "orderBook.h"

template <int NUM>
void OrderBook<NUM>::registerOrder(const char* orderId, double price, int quantity, buySell value)
{
  if (value == buy)
    {
      maxHeap_.push(Node(orderId, price, quantity));
    }
  else
    {
      minHeap_.push(Node(orderId, price, quantity));
    }

  checkExecution();
}

template <int NUM>
void OrderBook<NUM>::checkExecution()
{
  // check if there is a match in price
  LessThan<Node> comparator;

  unsigned int maxSize = (maxHeap_.size() > minHeap_.size())? minHeap_.size():maxHeap_.size();

  while(maxSize > 0)
    {
      if (comparator(minHeap_[0], maxHeap_[0]))
	{
	  // got a match
	  // lets match with the best price
	  int quantity = (minHeap_[0].quantity_ > maxHeap_[0].quantity_)?maxHeap_[0].quantity_:minHeap_[0].quantity_;
	  // consider all IOC and so pop first element
	  fptr_(productId_, maxHeap_[0].price_, quantity, minHeap_[0].orderId_);
	  fptr_(productId_, maxHeap_[0].price_, quantity, maxHeap_[0].orderId_);
	  maxHeap_.pop(quantity);
	  minHeap_.pop(quantity);

	  maxSize = (maxHeap_.size() > minHeap_.size())? minHeap_.size():maxHeap_.size();
	}
      else
	break;
    }

}

template <int NUM>
void OrderBook<NUM>::execution(int productId, double price, int execQty, string& orderId)
{
    cout  <<"Got an execution at ["
    << price << "] for quantity ["
    << execQty
    << "] for orderId ["
    << orderId
    << "] for product ["
    << productId
    << "]"
    << endl;
};