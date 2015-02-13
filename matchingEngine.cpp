#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#include "heap.h"
#include "orderBook.h"

using namespace std;


int main()
{
  OrderBook<3245> orderBook_VODL;
  OrderBook<5647> orderBook_BTL;

  orderBook_VODL.registerOrder("siril", 12.56, 20, orderBook_VODL.buy);
  orderBook_VODL.registerOrder("tejas", 12.66, 20, orderBook_VODL.buy);
  orderBook_VODL.registerOrder("gautam", 12.55, 10, orderBook_VODL.sell);
  orderBook_VODL.registerOrder("gautam", 12.55, 30, orderBook_VODL.sell);

  orderBook_BTL.registerOrder("siril", 12.76, 40, orderBook_BTL.buy);
  orderBook_BTL.registerOrder("tejas", 12.86, 20, orderBook_BTL.buy);
  orderBook_BTL.registerOrder("gautam", 12.55, 30, orderBook_BTL.sell);
  orderBook_BTL.registerOrder("gautam", 12.55, 30, orderBook_BTL.sell);
}
  
