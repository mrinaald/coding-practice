#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define MOD 1000000007

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

vector<llong> dp(100001, -1);
vector<llong> sumArr(100001, -1);
int k;

llong func(int n);

int main(){
	std::ios::sync_with_stdio(false);

	int t, a, b, i;
	llong ans;

	cin >> t >> k;

	for(i=0; i<=100000; ++i){
		ans = func(i);
	}

	ans = 0;
	sumArr[0] = func(0);
	for(i=1; i<=100000; ++i){
		sumArr[i] = ((sumArr[i-1]%MOD) + (func(i)%MOD))%MOD;
	}

	while(t--){
		cin >> a >> b;

		ans = ((sumArr[b]%MOD) - (sumArr[a-1]%MOD))%MOD;

		if(ans < 0)
			cout << ans + MOD << endl;
		else
			cout << ans << endl;

		// for(i=a; i<=b; ++i){
		//     ans = ((ans%MOD) + (func(i)%MOD))%MOD;
		// }
        //
		// cout << ans << endl;
	}

	return 0;
}

llong func(int n){
	if(n < k)
		return 1;

	if(n==k)
		return 2;

	if(dp[n] != -1)
		return dp[n];

	dp[n] = ((func(n-1)%MOD) + (func(n-k)%MOD))%MOD;
	// dp[n] = func(n-1) + func(n-k);

	return dp[n];
}
