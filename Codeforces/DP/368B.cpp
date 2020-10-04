#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

void computeDups();

vector<int> arr;
vector<bool> exist(100001, false);
vector<long long int> dp;

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, i;

	cin >> n >> m;
	arr.assign(n, 0);
	for(i=0; i<n; ++i){
		cin >> arr[i];
	}

	dp.assign(n, 0);
	computeDups();

	while(m--){
		cin >> i;
		cout << dp[i-1] << endl;
	}

	return 0;
}

void computeDups(){
	int n = arr.size();
	int i;
	dp[n-1] = 1;
	exist[arr[n-1]-1] = true;
	for(i=n-2; i>=0; --i){
		if(exist[arr[i]-1] == true){
			dp[i] = dp[i+1];
		}
		else{
			dp[i] = dp[i+1]+1;
			exist[arr[i]-1] = true;
		}
	}
}
