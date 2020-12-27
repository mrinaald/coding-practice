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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<llong> sum_heights(n);
  int i, h;
  cin >> h;
  sum_heights[0] = h;
  for (i=1; i<n; ++i) {
    cin >> h;
    sum_heights[i] = h + sum_heights[i-1];
  }

  llong min_h = sum_heights[k-1];
  llong sum;
  int min_h_id = 0;
  for (i=k; i<n; ++i) {
    sum = sum_heights[i] - sum_heights[i - k];
    if (sum < min_h) {
      min_h = sum;
      min_h_id = i-k+1;
    }
  }

  cout << min_h_id + 1 << "\n";
  cout << std::flush;
  return 0;
}
