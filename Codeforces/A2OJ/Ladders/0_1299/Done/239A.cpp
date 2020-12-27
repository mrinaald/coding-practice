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

  int y, k, n;
  cin >> y >> k >> n;

  int x;
  vector<int> ans;
  x = k - (y % k);
  if (x == 0)
    x += k;
  for (; (y + x) <= n; x+=k)
    ans.pb(x);

  if (ans.empty()) {
    cout << "-1\n";
  }
  else {
    for (x=0; x<ans.size(); ++x)
      cout << ans[x] << " ";
    cout << "\n";
  }

  cout << std::flush;
  return 0;
}
