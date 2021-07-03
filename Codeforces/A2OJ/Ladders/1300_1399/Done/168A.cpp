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

  int n, x, y;

  cin >> n >> x >> y;

  double a = (y * n) / 100.0;
  int b = (int) a;
  if (b < a) {
    ++b;
  }   // `b` denotes the ceil of the division stored in `a`

  if (x >= b) {
    cout << "0\n";
  } else {
    cout << b - x << "\n";
  }

  cout << std::flush;
  return 0;
}
