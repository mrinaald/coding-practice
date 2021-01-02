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

  const int n = 4;
  vector<string> arr(n);

  int i, j;
  for (i=0; i<n; ++i) {
    cin >> arr[i];
  }

  bool can_pass = false;
  for (i=1; i<n; ++i) {
    for (j=1; j<n; ++j) {
      if ((arr[i][j] == arr[i][j-1])
          && (arr[i][j] == arr[i-1][j])
          && (arr[i][j] == arr[i-1][j-1])) {
        can_pass = true;
        break;
      }
      else if (((arr[i][j] == arr[i][j-1]) && (arr[i][j] == arr[i-1][j]))
               || ((arr[i][j] == arr[i][j-1]) && (arr[i][j] == arr[i-1][j-1]))
               || ((arr[i][j] == arr[i-1][j]) && (arr[i][j] == arr[i-1][j-1]))
               || ((arr[i-1][j-1] == arr[i-1][j]) && (arr[i-1][j-1] == arr[i][j-1]))) {
        can_pass = true;
        break;
      }
    }
    if (can_pass)
      break;
  }

  if (can_pass)
    cout << "YES\n";
  else
    cout << "NO\n";

  cout << std::flush;
  return 0;
}
