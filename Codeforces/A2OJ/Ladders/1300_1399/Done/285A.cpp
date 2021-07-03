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

  vector<int> perm(n, 0);
  int i, j;
  for (i=0; i<n; ++i) {
    perm[i] = i+1;
  }

  i = n - 1 - k;
  j = n - 1;

  while (i < j) {
    swap(perm[i], perm[j]);
    ++i;
    --j;
  }

  for (i=0; i<n; ++i) {
    cout << perm[i] << " ";
  }
  cout << "\n";
  cout << std::flush;
  return 0;
}
