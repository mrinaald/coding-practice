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

int hex_to_int(char ch) {
  if ((ch >= '0') && (ch <= '9'))
    return ch - '0';
  else
    return ch - 'A' + 10;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<short>> arr(n+1, vector<short>(n+1, 0));
  string str;

  int i, j, x;
  int len = n / 4;
  for (i=1; i<=n; ++i) {
    cin >> str;

    for (j=0; j<len; ++j) {
      x = hex_to_int(str[j]);
      arr[i][(j << 2) + 1] = (x & 8) >> 3;
      arr[i][(j << 2) + 2] = (x & 4) >> 2;
      arr[i][(j << 2) + 3] = (x & 2) >> 1;
      arr[i][(j << 2) + 4] = (x & 1) & 1;
    }
  }

  // computing sum matrix
  vector<vector<long>> sum_arr(n+1, vector<long>(n+1, 0));
  sum_arr[1][1] = arr[1][1];
  for (i=2; i<=n; ++i) {
    sum_arr[1][i] = arr[1][i] + sum_arr[1][i-1];
    sum_arr[i][1] = arr[i][1] + sum_arr[i-1][1];
  }

  for (i=2; i<=n; ++i) {
    for (j=2; j<=n; ++j) {
      sum_arr[i][j] = arr[i][j] + sum_arr[i-1][j] - sum_arr[i-1][j-1] + sum_arr[i][j-1];
    }
  }

  bool can_compress = false;
  long sum1, sum2;
  for (x=n; x>=2; --x) {
    if (n%x != 0)
      continue;

    len = n / x;
    sum1 = ((long)x) * x;
    // cout << x << " - s1: " << sum1 << endl;
    can_compress = true;
    for (i=1; i<=len; ++i) {
      for (j=1; j<=len; ++j) {
        sum2 = sum_arr[i*x][j*x] - sum_arr[i*x][(j-1)*x] - sum_arr[(i-1)*x][j*x] + sum_arr[(i-1)*x][(j-1)*x];
        // cout << "(" << i*x << ", " << j*x << ") = " << sum2 << endl;

        if ((sum2 != 0) && (sum2 != sum1)) {
          can_compress = false;
          break;
        }
      }
      if (!can_compress)
        break;
    }

    if (can_compress)
      break;
  }

  // for (i=1; i<=n; ++i) {
  //   for (j=1; j<=n; ++j) {
  //     cout << arr[i][j];
  //   }
  //   cout << "\n";
  // }

  cout << x << endl;

  return 0;
}
