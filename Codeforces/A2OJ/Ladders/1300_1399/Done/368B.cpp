#include <iostream>
#include <vector>
#include <set>

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
  cin >> n >> m;

  vector<int> arr(n, 0);
  set<int> suffix_set;
  int i;

  for (i=0; i<n; ++i) {
    cin >> arr[i];
  }

  vector<int> suffix_arr(n);
  suffix_set.insert(arr[n-1]);
  suffix_arr[n-1] = suffix_set.size();
  for (i=n-2; i>=0; --i) {
    suffix_set.insert(arr[i]);
    suffix_arr[i] = suffix_set.size();
  }

  while (m--) {
    cin >> i;
    cout << suffix_arr[i-1] << "\n";
  }

  cout << std::flush;
  return 0;
}
