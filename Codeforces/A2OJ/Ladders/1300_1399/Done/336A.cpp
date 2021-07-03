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

  int x, y;
  cin >> x >> y;

  int x1, y1, x2, y2;
  x1 = x2 = y1 = y2 = 0;

  if (y > 0) {
    if (x > 0) {
      // 1st quadrant
      x2 = y1 = x + y;
    } else {
      // 2nd quadrant
      x1 = x - y;
      y2 = y - x;
    }
  } else {
    if (x < 0) {
      // 3rd quadrant
      x1 = y2 = x + y;
    } else {
      // 4th quadrant
      x2 = x - y;
      y1 = y - x;
    }
  }

  cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
  cout << std::flush;
  return 0;
}
