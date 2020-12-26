#include <iostream>
#include <cmath>

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

  int lb, bh, hl;
  cin >> lb >> bh >> hl;

  double d = sqrt((lb * hl) / bh);
  int l = (int) d;
  int b = lb / l;
  int h = hl / l;

  cout << 4 * (l + b + h) << "\n";

  cout << std::flush;
  return 0;
}
