#include "heap.h"

template <class Type, class Comparator>
void Heap<Type, Comparator>::siftDown(int node)
{
  int left = (node * 2) + 1;
  int right = left + 1;
  int siftIndex;

  if ((right < array_.size()) && comp_(array_[right],array_[left]))
    {
      siftIndex = right;
    }
  else
    {
      siftIndex = left;
    }

  if ((siftIndex < array_.size()) && comp_(array_[siftIndex],array_[node]))
    {
      swap(siftIndex, node);
      return siftDown(siftIndex);
    }
}


template <class Type, class Comparator>
void Heap<Type, Comparator>::siftUp(int node)
{
  int root = (node - 1) / 2;

  if (root < 0)
    return;

  if (comp_(array_[root], array_[node]))
    {
      swap(root, node);
      siftUp(root);
    }
}

template <class Type, class Comparator>
void Heap<Type, Comparator>::swap(int left, int right)
{
  Type tmp = array_[left];
  array_[left] = array_[right];
  array_[right] = tmp;
}

template <class Type, class Comparator>
void Heap<Type, Comparator>::push(const Type& value)
{
  array_.push_back(value);
  siftUp(array_.size() - 1);
}
