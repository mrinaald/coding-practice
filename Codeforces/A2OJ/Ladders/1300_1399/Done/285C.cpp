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

  int n;
  cin >> n;

  int i, a;
  ullong moves = 0;

  vector<int> arr(n, 0);

  for (i=0; i<n; ++i) {
    cin >> a;
    if (a < 1) {
      moves += (1 - a);
      arr[i] = 1;
    }
    else if (a > n) {
      moves += (a - n);
      arr[i] = n;
    }
    else {
      arr[i] = a;
    }
  }

  sort(all(arr));

  for (i=0; i<n; ++i) {
    if (arr[i] == i+1)
      continue;
    moves += abs(i + 1 - arr[i]);
  }

  cout << moves << "\n";
  cout << std::flush;
  return 0;
}
