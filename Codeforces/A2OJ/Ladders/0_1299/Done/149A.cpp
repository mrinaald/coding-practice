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

#define MAX_MONTHS 12

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;

  vector<int> arr(MAX_MONTHS, 0);
  int i;
  for (i=0; i<MAX_MONTHS; ++i)
    cin >> arr[i];

  if (k == 0) {
    cout << 0 << endl;
    return 0;
  }

  sort(rall(arr));
  int x = 0;

  for (i=0; i<MAX_MONTHS; ++i) {
    x += arr[i];
    if (x >= k)
      break;
  }

  if (i == MAX_MONTHS)
    cout << "-1\n";
  else
    cout << i+1 << "\n";

  cout << std::flush;
  return 0;
}
