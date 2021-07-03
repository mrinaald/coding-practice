#include <iostream>
#include <vector>

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

  int n, i;
  int total = 0;
  cin >> n;

  vector<int> bags(n, 0);
  for (i=0; i<n; ++i) {
    cin >> bags[i];
    total += bags[i];
  }

  int x;
  int no_steal = 0;
  for (i=0; i<n; ++i) {
    x = total - bags[i];
    if (x & 1) {
      no_steal++;
    }
  }

  cout << (n - no_steal) << "\n";

  cout << std::flush;
  return 0;
}
