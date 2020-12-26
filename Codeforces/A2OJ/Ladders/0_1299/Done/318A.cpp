#include <iostream>

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

  ullong n, k;
  cin >> n >> k;

  ullong center = (n / 2) + (n & 1);

  if (k <= center) {
    cout << (2 * k) - 1 << "\n";
  }
  else {
    cout << 2 * (k - center) << "\n";
  }

  cout << std::flush;
  return 0;
}
