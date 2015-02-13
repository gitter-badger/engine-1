#ifndef __ORDERBOOK_HPP__
#define __ORDERBOOK_HPP__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#include "heap.h"

using namespace std;

const double epsilon = (1E-6);

struct Node
{
  string orderId_;
  double price_;
  int quantity_;

  Node(const char* id, double price, int quantity): orderId_(id), price_(price), quantity_(quantity) {}

  void print() const
  {
    cout << orderId_ << " " << price_ << " " << quantity_ << endl;
  }
    
};

template <typename Type>
struct LessThan
{
  bool operator() (const Type& a, const Type& b)
  {
    return ((a - b) < -epsilon);
  }
};

template <>
struct LessThan<Node>
{
  LessThan<double> comp_;
  bool operator() (const Node& a, const Node& b)
  {
    return comp_(a.price_, b.price_);
  }
};

template <typename Type>
struct GreaterThan
{
  bool operator() (const Type& a, const Type& b)
  {
    return ((a - b) > epsilon);
  }
};

template <>
struct GreaterThan<Node>
{
  GreaterThan<double> comp_;
  bool operator() (const Node& a, const Node& b)
  {
    return comp_(a.price_, b.price_);
  }
};

//typedef void (*funcptr)(int productId, double price, int execQty, string& orderId);

template <int NUM>
class OrderBook
{
private:
  Heap<Node, GreaterThan<Node> > minHeap_; // sell side
  Heap<Node, LessThan<Node> > maxHeap_; // buy side
  
  //funcptr fptr_;
  int productId_;

public:
  enum buySell
    {
      buy = 0,
      sell
    };


  OrderBook():productId_(NUM) {}
  void registerOrder(const char* orderId, double price, int quantity, buySell value);
  //void registerExecutionCallback(funcptr fptr) { fptr_ = fptr; }
  void checkExecution();
  void execution(int productId, double price, int execQty, string& orderId);
};


#endif // __ORDERBOOK_HPP__
