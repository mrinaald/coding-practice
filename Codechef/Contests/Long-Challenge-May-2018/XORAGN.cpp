#include <iostream>
#include <vector>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, i;
	unsigned long long int a;
	cin >> t;

	while(t--){
		cin >> n;

		vector<unsigned long long int> nums;
		for(i=0; i<n; ++i){
			cin >> a;
			nums.push_back(a+a);
		}

		int xorValue = nums[0];
		for(i=1; i<n; ++i){
			xorValue = xorValue ^ nums[i];
		}

		cout << xorValue << endl;
	}
	return 0;
}
