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

  int i, a, q;
  int max_q = -1;
  int index = -1;

  for (i=1; i<=n; ++i) {
    cin >> a;
    q = (a / m) + (a % m != 0);
    if (q >= max_q) {
      max_q = q;
      index = i;
    }
  }

  cout << index << "\n";
  cout << std::flush;
  return 0;
}
