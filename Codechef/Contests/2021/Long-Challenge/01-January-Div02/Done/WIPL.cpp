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

#define INF 4005

int n, k;
vector<vector<int>> dp;
int compute_min_boxes(const vector<int> &h, int sum1, int sum2, int i);

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  int i;
  // int sum1, sum2;
  int min_boxes;
  while (t--) {
    cin >> n >> k;

    vector<vector<int>> dparr(k+1, vector<int>(k+1, -1));
    vector<int> heights(n, 0);
    int i;

    for (i=0; i<n; ++i) {
      cin >> heights[i];
    }

    sort(rall(heights));

    if (heights[0] >= k) {
      for (i=1; i<n; ++i) {
        if (k <= 0)
          break;
        k -= heights[i];
      }
      if (k <= 0)
        cout << i << "\n";
      else
        cout << "-1\n";
    }
    else {
      if (!dp.empty())
        dp.clear();
      dp.assign(2*k, vector<int>(2*k, -1));
      min_boxes = compute_min_boxes(heights, 0, 0, 0);
      if (min_boxes == INF) {
        cout << "-1\n";
      }
      else {
        cout << min_boxes << "\n";
      }
    }
  }

  cout << std::flush;
  return 0;
}

int compute_min_boxes(const vector<int> &h, int sum1, int sum2, int i) {
  if (sum1 >= k && sum2 >= k)
    return i;

  if (i == n)
    return INF;

  if (dp[sum1][sum2] != -1)
    return dp[sum1][sum2];

  if (sum1 >= k)
    return dp[sum1][sum2] = compute_min_boxes(h, sum1, sum2 + h[i], i+1);

  if (sum2 >= k)
    return dp[sum1][sum2] = compute_min_boxes(h, sum1 + h[i], sum2, i+1);

  if (sum1 == sum2)
    return dp[sum1][sum2] = compute_min_boxes(h, sum1 + h[i], sum2, i+1);

  return dp[sum1][sum2] = min(compute_min_boxes(h, sum1 + h[i], sum2, i+1),
                        compute_min_boxes(h, sum1, sum2 + h[i], i+1));
}
