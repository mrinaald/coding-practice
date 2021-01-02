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

  int n;
  cin >> n;

  int h, m;
  int ph, pm;
  int i;
  int cash;
  int max_cash = 1;

  cin >> h >> m;
  ph = h;
  pm = m;
  cash = 1;

  for (i=1; i<n; ++i) {
    cin >> h >> m;
    if (h == ph && m == pm) {
      ++cash;
    }
    else {
      if (cash > max_cash)
        max_cash = cash;
      ph = h;
      pm = m;
      cash = 1;
    }
  }

  if (cash > max_cash)
    max_cash = cash;

  cout << max_cash << "\n";

  cout << std::flush;
  return 0;
}
