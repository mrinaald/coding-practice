#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define MOD 1000000007

typedef long long int llong;
void func(int n, int k);
vector<vector<llong> > dp(2001, vector<llong>(2001, 0));

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	func(n, k);
	llong ans = 0;
	for(int i=1; i<=n; ++i){
		ans = ((ans%MOD) + (dp[i][k]%MOD))%MOD;
	}

	cout << ans << endl;

	return 0;
}

void func(int n, int k){
	int i, j, x, y;
	for(i=1; i<=n; ++i){
		dp[i][1] = 1;
	}
	for(i=1; i<k; ++i){
		for(j=1; j<=n; ++j){
			for(x=j; x<=n; x+=j){
				dp[x][i+1] = ((dp[x][i+1]%MOD) + (dp[j][i]%MOD))%MOD;
			}
		}
	}
	// if(k==1){
	//     dp[n][k] = 1;
	//     return 1;
	// }
	// if(n==1){
	//     dp[n][k] = 1;
	//     return 1;
	// }
	// if(dp[n][k] != -1)
	//     return dp[n][k];
    //
	// llong ans = func(n, k-1);
	// for(int i=n/2; i>=1; --i){
	//     if(n%i != 0)
	//         continue;
	//     ans = ((ans%MOD) + (func(i,k-1)%MOD))%MOD;
	// }
    //
	// dp[n][k] = ans;
	// return ans;
}
