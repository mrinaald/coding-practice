#include <iostream>
#include <vector>

using namespace std;

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

bool ifPossible(const vector<int> &coins, int id, int sum);

int main(){
  std::ios::sync_with_stdio(false);

  int t, n, m;
  int i;

  cin >> t;
  while(t--){
    cin >> n >> m;

    vector<int> coins(n);
    for(i=0; i<n; ++i){
      cin >> coins[i];
    }

    if (ifPossible(coins, 0, m))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}

bool ifPossible(const vector<int> &coins, int id, int sum){
  if (sum < 0)
    return false;
  if (sum == 0)
    return true;
  if (id == coins.size())
    return false;

  if (coins[id] > sum)
    return ifPossible(coins, id+1, sum);

  return ifPossible(coins, id+1, sum-coins[id]) || ifPossible(coins, id+1, sum);
}
