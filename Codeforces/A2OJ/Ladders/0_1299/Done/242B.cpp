#include <iostream>
#include <vector>
#include <set>
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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int i;
  int l, r;
  int min_l = 1000000001;
  int max_r = 0;
  set<int> min_l_set;
  set<int> max_r_set;
  for (i=1; i<=n; ++i) {
    cin >> l >> r;
    if (l < min_l) {
      min_l = l;
      min_l_set.clear();
      min_l_set.insert(i);
    }
    else if (l == min_l) {
      min_l_set.insert(i);
    }
    if (r > max_r) {
      max_r = r;
      max_r_set.clear();
      max_r_set.insert(i);
    }
    else if (r == max_r) {
      max_r_set.insert(i);
    }
  }

  vector<int> intersection(1, -1);
  set_intersection(all(min_l_set), all(max_r_set), intersection.begin());

  cout << intersection[0] << "\n";
  cout << std::flush;
  return 0;
}
