/************************************
 * WA and TLE
 ************************************/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

ullong computeWays(int n, int m, vector<ullong> &num_ways);
long int numSteadyTables(int n, int m, int orig_m, vector<ullong> &num_ways, vector<vector<long int>> &dparr);

int main(){
  std::ios::sync_with_stdio(false);

  int t, n, m;

  cin >> t;

  while(t--){
    cin >> n;
    cin >> m;

    vector<ullong> num_ways(2);
    vector<vector<long int>> dparr(n+1, vector<long int>(m+1, -1));
    num_ways[0] = 1;
    num_ways[1] = m;

    cout << numSteadyTables(n, m, m, num_ways, dparr)%MOD << endl;
    // cout << "**************************************************" << endl;
    // for(int i=0; i<num_ways.size(); ++i)
    //   cout << num_ways[i] << endl;
    // cout << "**************************************************" << endl;
  }

  return 0;
}

ullong computeWays(int sum, int vars, vector<ullong> &num_ways){
  if (sum == 0)
    return 1;
  if (sum == 1)
    return vars;

  if (sum < num_ways.size())
    return num_ways[sum];

  ullong temp = (computeWays(sum-1, vars, num_ways)*(sum+vars-1))/sum;
  num_ways.pb(temp);

  return temp;
}

long int numSteadyTables(int n, int sum, int orig_m, vector<ullong> &num_ways, vector<vector<long int>> &dparr){
  if (n == 0)
    return 1;
  if (sum == 0)
    return 1;
  if (dparr[n][sum] != -1)
    return dparr[n][sum];

  long int temp = 0;
  long int temp2;
  for(int i=sum; i>=0; --i){
    // temp += computeWays(i, orig_m, num_ways)*numSteadyTables(n-1, i, orig_m, num_ways);
    temp2 = ((computeWays(i, orig_m, num_ways)%MOD) * (numSteadyTables(n-1, i, orig_m, num_ways, dparr)%MOD))%MOD;
    temp = ((temp%MOD) + (temp2%MOD))%MOD;
  }

  dparr[n][sum] = temp;
  return temp;
}
