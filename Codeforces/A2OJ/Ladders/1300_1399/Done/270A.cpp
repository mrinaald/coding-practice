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

#define NO "NO\n"
#define YES "YES\n"

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, a;
  cin >> t;

  while (t--) {
    cin >> a;

    if (a < 60 || a > 180) {
      cout << NO;
      continue;
    }

    a = 180 - a;
    if (360 % a == 0) {
      cout << YES;
    } else {
      cout << NO;
    }
  }

  cout << std::flush;
  return 0;
}
