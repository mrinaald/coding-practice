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

int mergeSort(vector<int> &arr, int l, int r);
int merge(vector<int> &arr, int l, int m, int r);

vector<int> tempArr(100);

int main(){
  std::ios::sync_with_stdio(false);

  int t, n;
  int i;
  int local_inv;
  int invs;

  cin >> t;
  while(t--){
    cin >> n;

    vector<int> arr(n);
    for(i=0; i<n; ++i)
      cin >> arr[i];

    local_inv = 0;
    for(i=0; i<n-1; ++i){
      if (arr[i] > arr[i+1])
        local_inv++;
    }

    if (n == 1)
      invs = 0;
    else
      invs = mergeSort(arr, 0, n-1);

    cout << ((local_inv==invs)?"YES\n":"NO\n");
  }

  return 0;
}

int mergeSort(vector<int> &arr, int l, int r){
  if (l == r)
    return 0;
  if (l+1 == r){
    if (arr[l] > arr[r]){
      swap(arr[l], arr[r]);
      return 1;
    }
    else
      return 0;
  }

  int m = l + ((r-l)/2);
  int left_invs = mergeSort(arr, l, m);
  int right_invs = mergeSort(arr, m+1, r);
  int center_invs = merge(arr, l, m, r);

  return (left_invs + right_invs + center_invs);
}

int merge(vector<int> &arr, int l, int m, int r){
  int i = l;
  int j = m+1;
  int k = l;
  int invs = 0;

  while(i<=m && j<=r){
    if (arr[i] <= arr[j]){
      tempArr[k] = arr[i];
      k++;
      i++;
    }
    else{
      tempArr[k] = arr[j];
      k++;
      j++;
      invs += m-i+1;
    }
  }

  while(i<=m){
    tempArr[k++] = arr[i++];
  }

  while(j<=r){
    tempArr[k++] = arr[j++];
  }

  for(i=l; i<=r; ++i)
    arr[i] = tempArr[i];

  return invs;
}
