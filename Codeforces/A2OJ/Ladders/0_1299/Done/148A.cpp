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

  int k, l, m, n, d;
  cin >> k >> l >> m >> n >> d;

  int count = 0;
  for (int i=1; i<=d; ++i) {
    if (i % k == 0) {
      ++count;
      continue;
    }

    if (i % l == 0) {
      ++count;
      continue;
    }

    if (i % m == 0) {
      ++count;
      continue;
    }

    if (i % n == 0) {
      ++count;
      continue;
    }
  }

  cout << count << endl;

  cout << std::flush;
  return 0;
}
