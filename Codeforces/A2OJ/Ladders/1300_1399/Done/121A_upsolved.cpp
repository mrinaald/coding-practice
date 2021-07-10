#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_LUCKY 10000000000
vector<ullong> arr;

void init(ullong x) {
  if (x >= MAX_LUCKY)
    return;
  arr.pb(x);
  init(x*10 + 4);
  init(x*10 + 7);
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  init(0);
  sort(all(arr));

  ullong l, r;
  cin >> l >> r;

  ullong sum = 0;
  ullong ll, rl;
  for (size_t i=1; i<arr.size(); ++i) {
    ll = max(l, arr[i-1] + 1);
    rl = min(r, arr[i]);
    if (ll <= rl) {
      sum += (arr[i] * (rl - ll + 1));
    }
  }
  cout << sum << endl;

  cout << std::flush;
  return 0;
}
