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

  int n, t;
  cin >> n >> t;

  string q;
  cin >> q;

  int i;
  while (t--) {
    for (i=n-2; i>=0; --i) {
      if ((q[i] == 'B') && (q[i+1] == 'G')) {
        swap(q[i], q[i+1]);
        --i;  // Since q[i] should not be swapped again, decreasing i 2 times
      }
    }
  }

  cout << q << "\n";
  cout << std::flush;
  return 0;
}
