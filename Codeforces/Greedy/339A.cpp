#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	string str;
	vector<short> nums;
	int i;

	cin >> str;

	for(i=0; i<str.length(); i+=2){
		nums.push_back(str[i] - '0');
	}

	sort(nums.begin(), nums.end());

	int n = nums.size();
	for(i=0; i<n; ++i){
		if(i != (n-1))
			cout << nums[i] << '+' ;
		else
			cout << nums[i];
	}
	cout << endl;

	return 0;
}