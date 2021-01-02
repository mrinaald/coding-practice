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
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr(n, 0);
  vector<ullong> sum(n+1, 0);
  vector<ullong> sorted_sum(n+1, 0);
  int i;

  cin >> arr[0];
  sum[1] = arr[0];

  for (i=1; i<n; ++i) {
    cin >> arr[i];
    sum[i+1] = sum[i] + arr[i];
  }

  sort(all(arr));

  sorted_sum[1] = arr[0];
  for (i=1; i<n; ++i) {
    sorted_sum[i+1] = sorted_sum[i] + arr[i];
  }

  int m;
  cin >> m;

  int type, l, r;
  while (m--) {
    cin >> type >> l >> r;

    if (type == 1) {
      cout << sum[r] - sum[l-1] << "\n";
    }
    else if (type == 2) {
      cout << sorted_sum[r] - sorted_sum[l-1] << "\n";
    }
  }

  cout << std::flush;
  return 0;
}
