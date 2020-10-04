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

// My Quicksort gave TLE. Don't know the reason :(
void myQuickSort(vector<int> &arr, int left, int right);

int main(){
  // std::ios::sync_with_stdio(false);

  int n, d;
  scanf("%d %d", &n, &d);

  vector<int> arr(n);
  int i;
  for(i=0; i<n; ++i){
    scanf("%d", &arr[i]);
  }

  if (n <= 1){
    printf("0\n");
    return 0;
  }
  if (n == 2){
    if(arr[1] > arr[0]){
      printf(((arr[1]-arr[0] <= d)?"1\n":"0\n"));
    }
    else{
      printf(((arr[0]-arr[1] <= d)?"1\n":"0\n"));
    }
  }

  // myQuickSort(arr, 0, n-1);
  sort(all(arr));

  int count = 0;
  for(i=0; i<n-1; ++i){
    if(arr[i+1]-arr[i] <= d){
      count++;
      i++;
    }
  }

  printf("%d\n", count);

  return 0;
}

void myQuickSort(vector<int> &arr, int left, int right){
  if (left >= right)
    return;

  /*****************************************************************
   *** Method 1
  // int pivot = arr[right];
  // int i = left;
  // int j;
  // for(j=i; j<right; ++j){
  //   if (arr[j] < pivot){
  //     swap(arr[i], arr[j]);
  //     i++;
  //   }
  // }

  // swap(arr[i], arr[right]);
  // myQuickSort(arr, left, i-1);
  // myQuickSort(arr, i+1, right);
  *****************************************************************/


  /*****************************************************************
   *** Method 2
  int pivot = left;
  int i = left;
  int j = right;

  while(i<j){
    while(i<=j && arr[i]<=arr[pivot])
      i++;
    while(i<=j && arr[j]>arr[pivot])
      j--;
    if(i<j){
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[j], arr[pivot]);
  myQuickSort(arr, left, j-1);
  myQuickSort(arr, j+1, right);
  *****************************************************************/
}
