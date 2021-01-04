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

  int w;
  int one_count = 0;
  int two_count = 0;
  int total = 0;
  for (int i=0; i<n; ++i) {
    cin >> w;
    w /= 100;
    if (w == 1)
      one_count++;
    if (w == 2)
      two_count++;

    total += w;
  }

  if (total & 1) {
    cout << "NO" << endl;
    return 0;
  }

  int half = total / 2;
  if (half & 1) {
    if (one_count > 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  else {
    cout << "YES\n";
  }

  cout << std::flush;
  return 0;
}
