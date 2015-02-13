#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

template <class Type, class Comparator>
class Heap
{
private:
  vector<Type> array_;
  Comparator comp_;

public:

  void siftUp(int node);

  void siftDown(int node);

  void swap(int left, int right);

  void push(const Type& value);

  void print()
  {
    typename vector<Type>::const_iterator iter = array_.begin();
    for (; iter != array_.end(); ++iter)
      {
    	iter->print();
      }
  }

  int size()
  {
    return array_.size();
  }

  Type& operator[](int index)
  {
    return array_[index];
  }

  void pop(int quantity)
  {
    if (array_[0].quantity_ == quantity)
      array_.erase(array_.begin());
    else
      array_[0].quantity_ = array_[0].quantity_ - quantity;
  }
};

#endif // __HEAP_HPP__
