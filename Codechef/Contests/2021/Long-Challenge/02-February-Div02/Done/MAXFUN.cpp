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

  int n, t, i;
  llong max_sum;
  cin >> t;

  while(t--) {
    cin >> n;

    vector<int> arr(n, 0);
    for (i=0; i<n; ++i)
      cin >> arr[i];

    sort(all(arr));

    max_sum = arr[n-1];
    max_sum += arr[n-1];
    max_sum -= arr[0];
    max_sum -= arr[0];

    cout << max_sum << "\n";
  }

  cout << std::flush;
  return 0;
}
