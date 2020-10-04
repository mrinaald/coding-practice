#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool transform(vector<int> &nums, int k);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, k, temp;

	cin >> t;

	while(t--){
		cin >> n >> k;

		vector<int> nums;
		for(int i=0; i<n; ++i){
			cin >> temp;
			nums.push_back(temp);
		}

		if(transform(nums, k)){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}

	return 0;
}

bool transform(vector<int> &nums, int k){
	int n = nums.size();
	vector<int> remainders(k+1,0);

	for(int i=0; i<n; ++i){
		remainders[nums[i]%(k+1)]++;
	}

	for(int i=0; i<remainders.size(); ++i){
		if(remainders[i] >= n-1)
			return true;
	}

	return false;
}