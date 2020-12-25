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

  int n, m;
  cin >> n;

  int i, x;
  vector<int> pos(n+1, -1);
  for (i=0; i<n; ++i) {
    cin >> x;
    pos[x] = i;
  }

  cin >> m;
  ullong v = 0;
  ullong p = 0;
  for (i=0; i<m; ++i) {
    cin >> x;
    v += (pos[x] + 1);
    p += (n - pos[x]);
  }

  cout << v << " " << p << "\n";

  cout << std::flush;
  return 0;
}
