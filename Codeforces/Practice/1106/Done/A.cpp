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
  // std::ios::sync_with_stdio(false);
  int n;
  scanf("%d\n", &n);

  vector<vector<int>> M(2, vector<int>(n+2, 0));
  char ch;
  int r, c;
  int i, k;
  int count = 0;

  for (r=0; r<n; ++r) {
    for (c=1; c<=n; ++c) {
      scanf("%c", &ch);
      i = r % 2;
      if (ch == 'X') {
        M[i][c] = 1;
      }
      else if (ch == '.') {
        M[i][c] = 0;
      }

      if (r == 0)
        continue;

      k = (i + 1) % 2;
      if (M[i][c] == 1) {
        if ((M[k][c-1] > 0) && (M[k][c+1] > 0)) {
          M[i][c] = 3;
        }

        if (M[k][c+1] == 3) {
          M[k][c+1] = 4;
        }

        if (M[k][c-1] == 4) {
          count++;
        }
      }
    }
    scanf("%c", &ch);   // reading the last newline char
  }

  printf("%d\n", count);

  return 0;
}
