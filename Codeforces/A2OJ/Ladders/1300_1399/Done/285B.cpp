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

  int n, s, t;
  cin >> n >> s >> t;
  --s; --t;   // Converting to 0-based indexing

  vector<int> arr(n, 0);
  int i;
  for (i=0; i<n; ++i) {
    cin >> arr[i];
    arr[i]--;
  }

  if (s == t) {
    cout << 0 << endl;
    return 0;
  }

  int p = arr[s];
  int jumps = 1;
  while (p!=s && p!=t) {
    p = arr[p];
    ++jumps;
  }

  if (p == s) {
    // We never reached `t`
    cout << -1 << "\n";
  }
  else {
    // We reached `t`
    cout << jumps << "\n";
  }

  cout << std::flush;
  return 0;
}
