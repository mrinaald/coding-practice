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

  if (n & 1) {
    cout << -1 << "\n";
  }
  else {
    for (int i=1; i<=n; ++i) {
      if (i & 1) {
        cout << i+1 << " ";
      }
      else {
        cout << i-1 << " ";
      }
    }
    cout << "\n";
  }

  cout << std::flush;
  return 0;
}
