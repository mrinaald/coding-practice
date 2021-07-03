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

#define MAX_BIT 31

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, c;
  int a, b;
  int i, x;

  cin >> t;
  while (t--) {
    cin >> c;

    a = b = 0;
    for (i=MAX_BIT; i>=0; --i) {
      x = 1 << i;
      if (c & x) {
        if (a == 0) {
          a |= x;
        }
        else {
          b |= x;
        }
      }
      else {
        if (a == 0)
          continue;
        a |= x;
        b |= x;
      }
    }

    cout << ((llong)a) * b << "\n";
  }

  cout << std::flush;
  return 0;
}
