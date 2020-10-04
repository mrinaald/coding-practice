#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, x;
	cin >> t;

	while(t--)
	{
		cin >> n >> x;

		vector<int> arr;
		int temp;
		for(int i=0; i<n; ++i)
		{
			cin >> temp;
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end());

		int i=0;
		int j = n-1;
		bool flag = false;
		while(i<j)
		{
			if((arr[i]+arr[j]) < x)
				i++;
			else if((arr[i]+arr[j]) > x)
					j--;

			if((arr[i]+arr[j]) == x)
			{
				flag = true;
				break;
			}
		}
		if(flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}