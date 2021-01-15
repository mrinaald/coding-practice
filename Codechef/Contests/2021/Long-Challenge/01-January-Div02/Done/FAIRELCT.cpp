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

  int t, n, m;
  cin >> t;

  int i, j;
  int sum_john;
  int sum_jack;
  int num_swaps;

  while (t--) {
    cin >> n >> m;

    vector<int> john(n, 0);
    vector<int> jack(m, 0);


    sum_john = 0;
    sum_jack = 0;
    for (i=0; i<n; ++i) {
      cin >> john[i];
      sum_john += john[i];
    }
    for (j=0; j<m; ++j) {
      cin >> jack[j];
      sum_jack += jack[j];
    }

    if (sum_john > sum_jack) {
      cout << 0 << "\n";
      continue;
    }

    sort(all(john));
    sort(all(jack));

    i = 0;
    j = m-1;
    num_swaps = 0;
    while ((i < n) && (j >= 0)) {
      if (john[i] < jack[j]) {
        sum_john = sum_john - john[i] + jack[j];
        sum_jack = sum_jack - jack[j] + john[i];

        swap(john[i], jack[j]);
        ++num_swaps;

        if (sum_john > sum_jack)
          break;
      }
      else
        break;
      ++i;
      --j;
    }

    if (sum_john > sum_jack)
      cout << num_swaps << "\n";
    else
      cout << "-1\n";
  }

  cout << std::flush;
  return 0;
}
