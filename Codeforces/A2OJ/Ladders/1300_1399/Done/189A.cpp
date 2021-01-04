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

llong max_sticks(vector<llong> &dp, int n, const int a, const int b, const int c) {
  if (n == 0)
    return 0;
  if (n < 0)
    return -1;

  if (dp[n] != -2)
    return dp[n];

  llong x = -1;
  llong p;
  if (n >= a) {
    p = max_sticks(dp, n-a, a, b, c);
    if (p >= 0)
      x = max(x, 1 + p);
  }
  if (n >= b) {
    p = max_sticks(dp, n-b, a, b, c);
    if (p >= 0)
      x = max(x, 1 + p);
  }
  if (n >= c) {
    p = max_sticks(dp, n-c, a, b, c);
    if (p >= 0)
      x = max(x, 1 + p);
  }

  return dp[n] = x;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr(3, 0);
  cin >> arr[0] >> arr[1] >> arr[2];

  sort(all(arr));

  vector<llong> dp(n+1, -2);

  cout << max_sticks(dp, n, arr[0], arr[1], arr[2]) << "\n";
  cout << std::flush;
  return 0;
}
