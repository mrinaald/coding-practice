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

#define MAX_N 5

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> arr(MAX_N+1, vector<int>(MAX_N+1, 0));
  int i, j;
  for (i=1; i<=MAX_N; ++i) {
    for (j=1; j<=MAX_N; ++j) {
      cin >> arr[i][j];
    }
  }

  int i1, i2, i3, i4, i5;
  ullong happiness;
  ullong max_happiness = 0;
  for (i1=1; i1<=MAX_N; ++i1) {
    for (i2=1; i2<=MAX_N; ++i2) {
      if (i2 == i1)
        continue;
      for (i3=1; i3<=MAX_N; ++i3) {
        if (i3 == i1 || i3 == i2)
          continue;
        for (i4=1; i4<=MAX_N; ++i4) {
          if (i4 == i1 || i4 == i2 || i4 == i3)
            continue;
          for (i5=1; i5<=MAX_N; ++i5) {
            if (i5 == i1 || i5 == i2 || i5 == i3 || i5 == i4)
              continue;

            happiness = (arr[i1][i2] + arr[i2][i1]);
            happiness += (arr[i2][i3] + arr[i3][i2]);
            happiness += (2 * (arr[i3][i4] + arr[i4][i3]));
            happiness += (2 * (arr[i4][i5] + arr[i5][i4]));
            if (happiness > max_happiness)
              max_happiness = happiness;
          }
        }
      }
    }
  }

  cout << max_happiness << "\n";

  cout << std::flush;
  return 0;
}
