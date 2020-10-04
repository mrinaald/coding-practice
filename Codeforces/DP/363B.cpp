#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, k, i;
	cin >> n >> k;

	vector<int> heights(n, 0);
	long long int sum = 0;
	for(i=0; i<n; ++i){
		cin >> heights[i];
		if(i<k)
			sum += heights[i];
	}

	long long int minSum = sum;
	int minId = 1;
	for(i=1; i<=(n-k); ++i){
		sum = sum - heights[i-1] + heights[i+k-1];
		if(sum < minSum){
			minSum = sum;
			minId = i+1;
		}
	}

	cout << minId << endl;

	return 0;
}
