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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> arr(m, 0);
  int i;
  for (i=0; i<m; ++i)
    cin >> arr[i];

  sort(all(arr));

  i = 0;
  int j = i + n - 1;
  int min_diff = arr[m-1] - arr[0];

  for (; j<m; ++i, ++j) {
    if (arr[j] - arr[i] < min_diff) {
      min_diff = arr[j] - arr[i];
    }
  }

  cout << min_diff << endl;
  cout << std::flush;
  return 0;
}
