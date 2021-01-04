#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_NUM 7

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int i, x;
  int count[MAX_NUM + 1];
  for (i=0; i<=MAX_NUM; ++i)
    count[i] = 0;

  for (i=0; i<n; ++i) {
    cin >> x;
    count[x]++;
  }

  if (count[1] != (n/3) || count[5] > 0 || count[7] > 0) {
    cout << -1 << endl;
    return 0;
  }

  if (((count[2] + count[3]) != (n/3)) || ((count[4] + count[6]) != (n/3))) {
    cout << -1 << endl;
    return 0;
  }

  if (count[4] > count[2] || count[3] > count[6]) {
    cout << -1 << endl;
    return 0;
  }

  for (i=0; i<count[4]; ++i) {
    cout << "1 2 4\n";
  }
  count[2] -= count[4];
  count[4] = 0;

  for (i=0; i<count[2]; ++i) {
    cout << "1 2 6\n";
  }
  count[6] -= count[2];
  count[2] = 0;

  for (i=0; i<count[6]; ++i) {
    cout << "1 3 6\n";
  }
  count[3] -= count[6];
  count[6] = 0;

  cout << std::flush;
  return 0;
}
