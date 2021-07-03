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

#define FIRST "First\n"
#define SECOND "Second\n"

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n;
  int i;
  int moves;

  cin >> t;
  while (t--) {
    cin >> n;

    vector<int> arr(n, 0);
    vector<int> count(n+1, 0);
    vector<int> agg_count(n+1, 0);
    for (i=0; i<n; ++i) {
      cin >> arr[i];
      count[arr[i]]++;
    }

    for (i=1; i<=n; ++i) {
      agg_count[i] = agg_count[i-1] + count[i];
      // cout << i << " -> " << agg_count[i] << endl;
    }

    moves = 0;
    for (i=1; i<=n; ++i) {
      if (agg_count[i] < i)
        break;

      moves += n - agg_count[i];
    }

    if (i == n+1) {
      if (moves & 1) {
        cout << FIRST;
        // cout << "1: " << moves << " " << FIRST;
      }
      else {
        cout << SECOND;
        // cout << "1: " << moves << " " << SECOND;
      }
    }
    else {
      cout << SECOND;
      // cout << "2: " << moves << " " << SECOND;
    }
  }

  cout << std::flush;
  return 0;
}
