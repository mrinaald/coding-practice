#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, a, i;
	cin >> t;

	while(t--){
		cin >> n;

		vector<int> nums;
		for(i=0; i<n; ++i){
			cin >> a;
			nums.push_back(a);
		}

		int g = nums[0];
		for(i=1; i<n; ++i){
			g = gcd(nums[i], g);
		}

		if(g==1)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
