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

  int n, m, d;
  cin >> n >> m >> d;

  int len = n * m;
  vector<int> arr(len, 0);
  int i, a;

  cin >> a;
  int r = a % d;
  arr[0] = a / d;
  bool is_possible = true;

  for (i=1; i<len; ++i) {
    cin >> a;
    if ((a % d) != r) {
      is_possible = false;
    }
    arr[i] = a / d;
  }

  if (!is_possible) {
    cout << -1 << endl;
    return 0;
  }

  sort(all(arr));

  int mid = (len-1) / 2;
  llong moves = 0;
  for (i=0; i<len; ++i) {
    moves += abs(arr[mid] - arr[i]);
  }

  cout << moves << "\n";
  cout << std::flush;
  return 0;
}
