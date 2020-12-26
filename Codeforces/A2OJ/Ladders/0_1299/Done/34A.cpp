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

  int ph, h, fh;
  cin >> h;
  fh = h;

  int min_diff = 3000;
  int diff;

  int id1, id2;
  for (int i=1; i<n; ++i) {
    ph = h;
    cin >> h;

    diff = abs(ph - h);
    if (diff < min_diff) {
      min_diff = diff;
      id1 = i - 1;
      id2 = i;
    }
  }

  diff = abs(fh - h);
  if (diff < min_diff) {
    min_diff = diff;
    id1 = n - 1;
    id2 = 0;
  }

  cout << id1+1 << " " << id2+1 << "\n";

  cout << std::flush;
  return 0;
}
