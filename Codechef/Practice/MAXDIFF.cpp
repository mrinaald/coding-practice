#include <iostream>
#include <vector>

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

void quickSort(vector<int> &arr, int l, int r);
int findPivot(vector<int> &arr, int l, int r);
void print(vector<int> &arr, int n){
  for(int i=0; i<n; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

int main(){
  std::ios::sync_with_stdio(false);

  int t, n, k;
  int i;
  int lim;
  int chef;
  int son;

  cin >> t;
  while(t--){
    cin >> n >> k;

    vector<int> arr(n);
    for(i=0; i<n; ++i){
      cin >> arr[i];
    }

    quickSort(arr, 0, n-1);
    print(arr, n);
    if (k > n/2)
      lim = n-k;
    else
      lim = k;

    chef = son = 0;
    for(i=0; i<lim; ++i){
      son += arr[i];
    }
    for(i=lim; i<n; ++i){
      chef += arr[i];
    }

    cout << chef-son << "\n";
  }

  return 0;
}

void quickSort(vector<int> &arr, int l, int r){
  if (l >= r)
    return;
  if (l+1 == r){
    if (arr[l] > arr[r])
      swap(arr[l], arr[r]);

    return;
  }

  int pivot = findPivot(arr, l, r);
  // cout << arr[id] << " " << pivot << endl;
  // swap(arr[id], arr[pivot]);

  if (l != pivot)
    quickSort(arr, l, pivot-1);

  quickSort(arr, pivot+1, r);
}

int findPivot(vector<int> &arr, int l, int r){
  int id = l;
  int i = l;
  int j = r;

  while(i<j){
    while((i<j) && (arr[i]<=arr[id]))
      i++;
    while((i<=j) && (arr[j]>arr[id]))
      j--;

    if (i < j){
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  swap(arr[id], arr[j]);
  return j;
}
