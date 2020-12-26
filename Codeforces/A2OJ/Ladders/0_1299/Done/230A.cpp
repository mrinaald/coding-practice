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

bool my_compare(const std::pair<ullong, ullong> &lhs, const std::pair<ullong, ullong> &rhs) {
  if (lhs.first < rhs.first)
    return true;
  else if (lhs.first > rhs.first)
    return false;
  else {
    if (lhs.second >= rhs.second)
      return true;
    else
      return false;
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ullong s;
  int n;
  cin >> s >> n;

  vector<std::pair<ullong, ullong> > arr(n);
  int i;
  for (i=0; i<n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(all(arr), my_compare);
  for (i=0; i<n; ++i) {
    if (s <= arr[i].first)
      break;
    s += arr[i].second;
  }

  if (i == n) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
  cout << std::flush;
  return 0;
}
