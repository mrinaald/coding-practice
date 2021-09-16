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

  string str;
  int n, m, l, r, i;

  cin >> str;
  n = str.length();

  vector<llong> sum_arr(n, 0);

  sum_arr[0] = 0;
  for (i=1; i<n; ++i) {
    if (str[i] == str[i-1]) {
      sum_arr[i] = sum_arr[i-1] + 1;
    } else {
      sum_arr[i] = sum_arr[i-1];
    }
  }

  cin >> m;
  while (m--) {
    cin >> l >> r;
    --l;
    --r;
    cout << sum_arr[r] - sum_arr[l] << "\n";
  }

  cout << std::flush;
  return 0;
}
