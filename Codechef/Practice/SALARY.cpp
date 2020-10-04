#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

void myQuickSort(vector<int> &arr, int left, int right);

int main(){
  // std::ios::sync_with_stdio(false);

  int t, n;
  int i;
  ulong ops;

  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);

    vector<int> arr(n);
    for(i=0; i<n; ++i)
      scanf("%d", &arr[i]);

    ops = 0;
    myQuickSort(arr, 0, n-1);
    // sort(all(arr));

    i = n-1;
    while(i > 0){
      while(i>0 && arr[i]==arr[i-1])
        i--;
      if (i == 0)
        break;

      ops += (n-i)*(arr[i]-arr[i-1]);
      i--;
    }

    printf("%lu\n", ops);
  }


  return 0;
}

void myQuickSort(vector<int> &arr, int left, int right){
  if (left >= right)
    return;

  int pivot = right;
  int i = left;
  int j = left;

  while(j < right){
    if (arr[j] < arr[pivot]){
      swap(arr[i], arr[j]);
      i++;
    }
    j++;
  }

  swap(arr[i], arr[pivot]);
  myQuickSort(arr, left, i-1);
  myQuickSort(arr, i+1, right);
}
