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

  int n, m;
  cin >> n >> m;

  int i, a;
  int curr = 1;
  ullong t = 0;
  for (i=0; i<m; ++i) {
    cin >> a;
    if (a == curr) {
      continue;
    }
    else if (curr < a) {
      t += (a - curr);
      curr = a;
    }
    else {
      t += (a - curr + n);
      curr = a;
    }
  }

  cout << t << "\n";
  cout << std::flush;
  return 0;
}
