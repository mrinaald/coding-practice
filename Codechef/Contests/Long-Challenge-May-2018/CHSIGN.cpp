#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int changeSign(vector<int> &arr, int n);
int min(int a, int b){
	return (a<b)?a:b;
}

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, i, j, k, temp;

	cin >> t;
	while(t--){
		cin >> n;

		vector<int> arr;
		for(i=0; i<n; ++i){
			cin >> temp;
			arr.pb(temp);
		}

		cout << changeSign(arr, n) << endl;
	}

	return 0;
}

int changeSign(vector<int> &arr, int n){
	int i;
	vector<int> sumArr[2];

	if(arr[0] < arr[1]){
		sumArr[0].pb(-arr[0]);
	}
	else{
		sumArr[0].pb(arr[0]);
	}
	sumArr[1].pb(arr[0]);

	for(i=1; i<(n-1); ++i){
		if((arr[i] < arr[i-1]) && (arr[i] < arr[i+1])){
			sumArr[0].pb(min(sumArr[0][i-1]-arr[i], sumArr[1][i-1]-arr[i]));
			sumArr[1].pb(min(sumArr[0][i-1]+arr[i], sumArr[1][i-1]+arr[i]));
		}
		else{
			sumArr[0].pb(sumArr[0][i-1] + arr[i]);
			sumArr[1].pb(sumArr[1][i-1] + arr[i]);
		}
	}

	if(arr[n-1] < arr[n-2]){
		sumArr[0].pb(min(sumArr[0][n-2]-arr[n-1], sumArr[1][n-2]-arr[n-1]));
		sumArr[1].pb(min(sumArr[0][n-2]+arr[n-1], sumArr[1][n-2]+arr[n-1]));
	}
	else{
		sumArr[0].pb(min(sumArr[0][n-2]+arr[n-1], sumArr[1][n-2]+arr[n-1]));
		sumArr[1].pb(min(sumArr[0][n-2]+arr[n-1], sumArr[1][n-2]+arr[n-1]));
	}

	return min(sumArr[0][n-1], sumArr[1][n-1]);
}
