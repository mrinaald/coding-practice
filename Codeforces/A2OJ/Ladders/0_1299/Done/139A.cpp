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

#define MAX_DAYS 7

int find_day(const int n, const vector<int> &sum) {
  for (int i=0; i<MAX_DAYS; ++i) {
    if (sum[i] >= n) {
    // if ((sum[i] > 0) && (sum[i] >= n)) {
      return i+1;
    }
  }
  return 0;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> sum(MAX_DAYS, 0);
  cin >> sum[0];
  for (int i=1; i<MAX_DAYS; ++i) {
    cin >> sum[i];
    sum[i] += sum[i-1];
  }

  if (sum[MAX_DAYS - 1] < n) {
    n = n % sum[MAX_DAYS - 1];
    if (n == 0)
      n = sum[MAX_DAYS - 1];
  }

  cout << find_day(n, sum) << "\n";
  cout << std::flush;
  return 0;
}
