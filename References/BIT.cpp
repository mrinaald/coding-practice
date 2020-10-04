/*************************************************************************
 *** https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
 *************************************************************************/

#include <iostream>
using namespace std;

#define rint register int

int* constructBITree(const int *arr, int n);
int getSum(const int* BIT, int id);
void updateBIT(int *BIT, int n, int id, int x);

int main(){
  int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(freq)/sizeof(freq[0]);

  int *BITree = constructBITree(freq, n);

  cout << "Sum of elements in arr[0..5] is "
       << getSum(BITree, 5);

  freq[3] += 6;
  updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]

  cout << "\nSum of elements in arr[0..5] after update is "
       << getSum(BITree, 5) << endl;

  return 0;
}


int* constructBITree(const int *arr, int n){
  int *BIT = new int[n+1];

  for(rint i=0; i<=n; ++i)
    BIT[i] = 0;

  for(rint i=0; i<n; ++i){
    updateBIT(BIT, n, i, arr[i]);
  }

  return BIT;
}


int getSum(const int* BIT, int id){
  int sum = 0;

  id++;
  while(id > 0){
    sum += BIT[id];
    id -= (id & -id);
  }

  return sum;
}


void updateBIT(int *BIT, int n, int id, int x){
  id++;

  while(id <= n){
    BIT[id] += x;
    id += (id & -id);
  }
}
