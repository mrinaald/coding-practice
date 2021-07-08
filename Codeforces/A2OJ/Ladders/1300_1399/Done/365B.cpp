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

  vector<llong> arr(n, 0);
  int i;
  for (i=0; i<n; ++i) {
    cin >> arr[i];
  }

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 2) {
    cout << 2 << endl;
    return 0;
  }

  int max_len = 0;
  int len = 0;
  for (i=2; i<n; ++i) {
    if (arr[i] == (arr[i-1] + arr[i-2])) {
      len++;
    } else {
      if (len > max_len) {
        max_len = len;
      }
      len = 0;
    }
  }
  if (len > max_len) {
    max_len = len;
  }

  cout << max_len + 2 << "\n";

  cout << std::flush;
  return 0;
}
