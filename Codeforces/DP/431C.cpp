#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define MOD 1000000007

long long int func(int n, short taken);
int k, d;
vector<vector<long long int> > dp(101, vector<long long int>(2, -1));

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n >> k >> d;

	cout << func(n, 0)%MOD << endl;

	return 0;
}

long long int func(int n, short taken){
	if(n<0)
		return 0;
	if(n==0){
		if(taken==0)
			return 0;
		else
			return 1;
	}

	if(dp[n][taken] != -1)
		return dp[n][taken];

	int i;
	long long int x = 0;

	for(i=1; i<=k; ++i){
		if(i>n)
			break;
		if(i >= d ){
			x = ((x%MOD) + (func(n-i, 1)%MOD))%MOD;
		}
		else{
			x = ((x%MOD) + (func(n-i, taken)%MOD))%MOD;
		}
	}
	dp[n][taken] = x;

	return dp[n][taken];
}
