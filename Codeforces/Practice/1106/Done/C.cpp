#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
  // std::ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);

  int i, a;
  vector<int> arr(n);

  for (i=0; i<n; ++i) {
    scanf("%d", &a);
    arr[i] = a;
  }

  sort(all(arr));

  int l = 0;
  int r = n-1;
  ullong min_sum = 0;
  ullong x;

  while (l < r) {
    x = (arr[l] + arr[r]);
    min_sum += (x * x);
    l++;
    r--;
  }

  printf("%llu\n", min_sum);

  return 0;
}
