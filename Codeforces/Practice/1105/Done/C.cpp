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

#define MOD 1000000007

int n;
ullong m0, m1, m2;

void find_lost_arrays(vector<vector<ullong>>& arr);

int main(){
  // std::ios::sync_with_stdio(false);
  int l, r;

  scanf("%d %d %d", &n, &l, &r);

  vector<vector<ullong>> dp_arr(n+1, vector<ullong>(3, 0));

  m0 = m1 = m2 = 0;

  {
    // scoping to not hold extra memory for these
    // 4 variables
    llong rd, ld, rr, lr;
    ld = l / 3;
    lr = l % 3;
    rd = r / 3;
    rr = r % 3;

    m0 = (rd - ld) + (lr == 0);
    m1 = (rd - ld) + (rr >= 1) - (lr == 2);
    m2 = (rd - ld) + (rr == 2);
  }

  dp_arr[1][0] = m0;
  dp_arr[1][1] = m1;
  dp_arr[1][2] = m2;

  find_lost_arrays(dp_arr);

  printf("%llu\n", dp_arr[n][0]);

  return 0;
}

void find_lost_arrays(vector<vector<ullong>>& arr) {
  int i;
  ullong t1, t2, t3, t4;

  for (i=2; i<=n; ++i) {
    // Computing arr[i][0]
    t1 = ((arr[i-1][0] % MOD) * (m0 % MOD)) % MOD;
    t2 = ((arr[i-1][1] % MOD) * (m2 % MOD)) % MOD;
    t3 = ((arr[i-1][2] % MOD) * (m1 % MOD)) % MOD;

    t4 = ((t1 % MOD) + (t2 % MOD)) % MOD;
    t4 = ((t4 % MOD) + (t3 % MOD)) % MOD;

    arr[i][0] = t4;


    // Computing arr[i][1]
    t1 = ((arr[i-1][0] % MOD) * (m1 % MOD)) % MOD;
    t2 = ((arr[i-1][1] % MOD) * (m0 % MOD)) % MOD;
    t3 = ((arr[i-1][2] % MOD) * (m2 % MOD)) % MOD;

    t4 = ((t1 % MOD) + (t2 % MOD)) % MOD;
    t4 = ((t4 % MOD) + (t3 % MOD)) % MOD;

    arr[i][1] = t4;


    // Computing arr[i][2]
    t1 = ((arr[i-1][0] % MOD) * (m2 % MOD)) % MOD;
    t2 = ((arr[i-1][1] % MOD) * (m1 % MOD)) % MOD;
    t3 = ((arr[i-1][2] % MOD) * (m0 % MOD)) % MOD;

    t4 = ((t1 % MOD) + (t2 % MOD)) % MOD;
    t4 = ((t4 % MOD) + (t3 % MOD)) % MOD;

    arr[i][2] = t4;
  }
}
