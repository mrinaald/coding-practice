#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define PENALTY -1000000000

llong solve(vector<llong>& sum, vector<vector<llong>>& dp, int n, int m, int i, int k) {
  if (k <= 0) {
    return 0;
  }
  if (i > (n - (m * k) + 1)) {
    return PENALTY;
  }
  if (dp[i][k] != -1) {
    return dp[i][k];
  }

  dp[i][k] = max(solve(sum, dp, n, m, i+m, k-1) + sum[i+m-1] - sum[i-1],
                 solve(sum, dp, n, m, i+1, k));
  return dp[i][k];
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> arr(n, 0);
  int i;
  for (i=0; i<n; ++i) {
    cin >> arr[i];
  }

  vector<llong> sum(n+1, 0);
  for (i=1; i<=n; ++i) {
    sum[i] = sum[i-1] + arr[i-1];
  }

  // for (i=0; i<=n; ++i) {
  //   cout << sum[i] << " ";
  // }
  // cout << endl;

  vector<vector<llong>> dp(n+1, vector<llong>(k+1, -1));
  cout << solve(sum, dp, n, m, 1, k) << "\n";

  cout << std::flush;
  return 0;
}
