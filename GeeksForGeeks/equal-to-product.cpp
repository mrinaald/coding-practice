#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t, n;
	long long int p;

	cin >> t;

	while(t--)
	{
		cin >> n >> p;

		vector<int> arr;
		int temp;

		for(int i=0; i<n; ++i)
		{
			cin >> temp;
			arr.push_back(temp);
		}

		bool flag = false;
		for(int i=0; i<n; ++i)
		{
			for(int j=i+1; j<n; ++j)
			{
				if((arr[i]*arr[j])==p)
				{
					flag = true;
					break;
				}
			}
			
			if(flag)
				break;
		}

		cout << ((flag)?"Yes\n":"No\n");

	}
}