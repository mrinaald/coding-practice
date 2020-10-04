/***********************************************
 *** https://www.geeksforgeeks.org/binary-heap/
 **********************************************/

#include <iostream>
#include <climits>
using namespace std;

#define rint register int

void swap(int &a, int &b){
  int c = b;
  b = a;
  a = c;
}

class MinHeap{
  int *arr;
  int size;
  int capacity;

public:
  MinHeap(int n){
    capacity = n;
    size = 0;
    arr = new int[n];
  }

  void MinHeapify(int id){
    int left = leftChild(id);
    int right = rightChild(id);
    int smallest = id;

    if (left<size && arr[left]<arr[smallest])
      smallest = left;
    if (right<size && arr[right]<arr[smallest])
      smallest = right;

    if (smallest != id){
      swap(arr[id], arr[smallest]);
      MinHeapify(smallest);
    }
  }

  int parent(int id){
    return (id-1)/2;
  }

  int leftChild(int id){
    return 2*id+1;
  }

  int rightChild(int id){
    return 2*id+2;
  }

  void insertKey(int key){
    if (size == capacity){
      cout << "Heap is full. Please delete some keys first\n";
      return;
    }

    arr[size] = key;
    int i = size;
    size++;

    int p;
    while(i > 0){
      p = parent(i);
      if (arr[p] > arr[i])
        swap(arr[p], arr[i]);

      i = p;
    }
  }

  void deleteKey(int key){
    if (size == 0){
      cout << "Heap is empty\n";
      return;
    }

    decreaseKey(key, INT_MIN);
    extractMin();
  }

  int extractMin(){
    if (size == 0)
      return INT_MIN;

    int element = arr[0];
    arr[0] = arr[size-1];
    size--;
    MinHeapify(0);

    return element;
  }

  int getMin(){
    if (size == 0)
      return INT_MIN;

    return arr[0];
  }

  void decreaseKey(int key, int value){
    if (key >= size){
      cout << "Key " << key << " does not exist\n";
      return;
    }

    arr[key] = value;
    int i = key;
    int p;

    while(i > 0){
      p = parent(i);
      if (arr[p] > arr[i])
        swap(arr[p], arr[i]);

      i = p;
    }
  }

  int getSize(){
    return size;
  }
};

int main(){
  MinHeap h(11);
  h.insertKey(3);
  h.insertKey(2);

  h.deleteKey(1);

  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);

  cout << h.extractMin() << " ";
  cout << h.getMin() << " ";

  h.decreaseKey(2, 1);

  cout << h.getMin();
  cout << endl;
  return 0;
}
