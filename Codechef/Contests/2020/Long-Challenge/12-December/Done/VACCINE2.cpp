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

  int T, N, D, a;
  int i, r, nr;

  cin >> T;
  while (T--) {
    cin >> N >> D;

    r = nr = 0;

    for (i=0; i<N; ++i) {
      cin >> a;
      if ((a <= 9) || (a >= 80))
        ++r;
      else
        ++nr;
    }

    i = (r / D) + ((r % D) != 0) + (nr / D) + ((nr % D) != 0);
    cout << i << "\n";
  }

  cout << std::flush;
  return 0;
}
