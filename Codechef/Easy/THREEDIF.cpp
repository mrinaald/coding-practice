#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

typedef unsigned long long int ullong;

int main()
{
	std::ios::sync_with_stdio(false);

	int t;
	ullong count;
	ullong temp1, temp2;
	ullong n1, n2, n3;
	ullong i, j, k;

	cin >> t;
	while(t--)
	{
		cin >> n1 >> n2 >> n3;
		count = 0;
		vector<ullong> nums;
		nums.push_back(n1);
		nums.push_back(n2);
		nums.push_back(n3);

		sort(nums.begin(), nums.end());

		n1 = nums[0];
		n2 = nums[1];
		n3 = nums[2];

		count = ((n1%MOD) * ((n2-1)%MOD)%MOD * ((n3-2)%MOD)%MOD)%MOD;

		cout << count << endl;
	}

	return 0;
}