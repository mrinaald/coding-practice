/*************************************************************************
 *** https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
 *************************************************************************/

#include <iostream>

using namespace std;

#define MAX_NODES 100000
#define rint register int

void buildTree(const int *arr);
void updateTreeNode(int index, int value);
int query(int l, int r);

int tree[MAX_NODES];
int n;

int main(){
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  n = sizeof(a)/sizeof(a[0]);

  // build tree
  buildTree(a);

  // print the sum in range [1,2] (0-index based)
  cout << query(1, 3)<<endl;

  // modify element at 2nd index (0-index based)
  updateTreeNode(2, 1);

  // print the sum in range [1,2] (0-index based)
  cout << query(1, 3)<<endl;

  return 0;
}


void buildTree(const int *arr){
  for(rint i=0; i<n; ++i){
    tree[n+i] = arr[i];
  }

  for(rint i=n-1; i>0; --i){
    tree[i] = tree[2*i] + tree[2*i + 1];
  }
}


void updateTreeNode(int index, int value){
  tree[index+n] = value;

  for(rint i=index/2; i>0; i /= 2)
    tree[i] = tree[2*i] + tree[2*i + 1];
}


int query(int l, int r){
  int sum = 0;

  for(l=n+l, r=n+r; l<r; l/=2, r/=2){
    if (l%2){
      sum += tree[l];
      l++;
    }
    if (r%2){
      r--;
      sum += tree[r];
    }
  }

  return sum;
}
