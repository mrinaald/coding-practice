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

  int n;
  cin >> n;

  vector<int> arr(n, 0);
  int i, j;

  for (i=0; i<n; ++i) {
    cin >> arr[i];
  }

  if (n == 1) {
    cout << "yes\n";
    cout << "1 1" << endl;
    return 0;
  }

  int l, r;

  // Find 'l' upto which sequence is increasing
  l = 1;
  while ((l < n) && (arr[l] > arr[l-1]))
    ++l;

  if (l == n) {
    // array is already sorted
    cout << "yes\n";
    cout << "1 1" << endl;
    return 0;
  }

  // Find 'r' upto which sequence is decreasing
  r = l;
  --l;
  while ((r < n) && (arr[r] < arr[r-1]))
    ++r;

  --r;

  // see whether reversing [l, r] will be sorted in the left-over sequence
  if (l > 0) {
    if (arr[r] < arr[l-1]) {
      cout << "no" << endl;
      return 0;
    }
  }

  if (r < n-1) {
    if (arr[l] > arr[r+1]) {
      cout << "no" << endl;
      return 0;
    }
  }

  // reverse b/w l and r
  for (i=l, j=r; i<j; ++i, --j) {
    swap(arr[i], arr[j]);
  }

  // Check whether array is sorted finally or not
  for (i=1; i<n; ++i) {
    if (arr[i] < arr[i-1])
      break;
  }

  if (i == n) {
    cout << "yes\n";
    cout << l+1 << " " << r+1 << "\n";
  }
  else {
    cout << "no\n";
  }

  cout << std::flush;
  return 0;
}
