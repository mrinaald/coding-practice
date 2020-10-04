#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, i, sum, temp;

	cin >> n;
	sum = 0;

	vector<int> coins;
	for(i=0; i<n; ++i){
		cin >> temp;
		sum += temp;
		coins.pb(temp);
	}

	sort(all(coins));

	int numCoins = 0;
	int myCoinSum = 0;
	for(i=n-1; i>=0; --i){
		if(myCoinSum > sum)
			break;
		myCoinSum += coins[i];
		sum -= coins[i];
		numCoins++;
	}

	cout << numCoins << endl;

	return 0;
}
