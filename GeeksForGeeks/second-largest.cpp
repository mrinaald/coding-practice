#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t, n;
	cin >> t;

	while(t--)
	{
		cin >> n;

		// vector<int> arr;
		int temp;

		cin >> temp;
		// arr.push_back(temp);

		int max1=0;
		int max2=0;

		if(temp>max1)
		{
			max2 = max1;
			max1 = temp;
		}

		for(int i=1; i<n; ++i)
		{
			cin >> temp;
			if(temp>max1)
			{
				max2 = max1;
				max1 = temp;
			}
			else if(temp>max2)
			{
				max2 = temp;
			}
		}
		cout << max2 << endl;
	}
	return 0;
}