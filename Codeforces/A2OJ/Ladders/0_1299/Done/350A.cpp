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

int get_tl(const int mina, const int maxa, const int minb, const int maxb) {
  if (minb <= maxa)
    return -1;

  int mina2 = 2 * mina;
  for (int t=maxa; t<minb; ++t) {
    if (mina2 <= t)
      return t;
  }
  return -1;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int a, b, i;
  int min_a, max_a;
  int min_b, max_b;

  cin >> a;
  min_a = max_a = a;
  for (i=1; i<n; ++i) {
    cin >> a;
    if (a < min_a) {
      min_a = a;
    }
    if (a > max_a) {
      max_a = a;
    }
  }

  cin >> b;
  min_b = max_b = b;
  for (i=1; i<m; ++i) {
    cin >> b;
    if (b < min_b) {
      min_b = b;
    }
    if (b > max_b) {
      max_b = b;
    }
  }

  cout << get_tl(min_a, max_a, min_b, max_b) << "\n";

  cout << std::flush;
  return 0;
}
