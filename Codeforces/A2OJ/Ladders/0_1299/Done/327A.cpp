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

  vector<int> count0(n+1, 0);
  vector<int> count1(n+1, 0);
  int i, a;

  cin >> a;
  if (a == 0)
    count0[1] = 1;
  else
    count1[1] = 1;

  for (i=1; i<n; ++i) {
    cin >> a;
    if (a == 0) {
      count0[i+1] = count0[i] + 1;
      count1[i+1] = count1[i];
    }
    else {
      count0[i+1] = count0[i];
      count1[i+1] = count1[i] + 1;
    }
  }

  int l, r;
  int max_count = 0;
  int count;
  for (l=1; l<=n; ++l) {
    for (r=l; r<=n; ++r) {
      count = (count1[l-1]) + (count0[r] - count0[l-1]) + (count1[n] - count1[r]);
      if (count > max_count)
        max_count = count;
    }
  }

  cout << max_count << "\n";
  cout << std::flush;
  return 0;
}
