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

struct Element {
  llong a;
  llong total_decs = 0;
};

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<Element> arr(n);
  int i;
  for (i=0; i<n; ++i) {
    cin >> arr[i].a;
  }

  int t, v, x, y, q;
  llong total_incs = 0;
  while (m--) {
    cin >> t;
    switch (t) {
    case 1:
      cin >> v >> x;
      v--;
      arr[v].a = x;
      arr[v].total_decs = -total_incs;
      break;

    case 2:
      cin >> y;
      total_incs += y;
      break;

    case 3:
      cin >> q;
      q--;
      cout << arr[q].a + total_incs + arr[q].total_decs << "\n";
      break;
    }
  }

  cout << std::flush;
  return 0;
}
