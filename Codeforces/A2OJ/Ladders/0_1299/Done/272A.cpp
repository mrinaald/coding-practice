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

  int i, f;
  int s = 0;
  for (i=0; i<n; ++i) {
    cin >> f;
    s += f;
  }

  int c = 0;
  for (i=1; i<=5; ++i) {
    if (((s + i) % (n + 1)) == 1)
      continue;
    ++c;
  }

  cout << c << "\n";
  cout << std::flush;
  return 0;
}
