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

  int n, k;
  cin >> n >> k;

  vector<int> arr(n, 0);
  int i;
  for (i=0; i<n; ++i)
    cin >> arr[i];

  --k;    // making k 0-based index
  for (i=k+1; i<n; ++i) {
    if (arr[i] != arr[i-1])
      break;
  }

  if (i != n) {
    // there are non-unique elements after k-index
    cout << -1 << endl;
    return 0;
  }

  for (i=k-1; i>=0; --i) {
    if (arr[i] != arr[i+1])
      break;
  }

  cout << i+1 << "\n";

  cout << std::flush;
  return 0;
}
