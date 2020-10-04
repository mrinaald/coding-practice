#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, k;
	char j;

	cin >> t;
	while(t--)
	{
		cin >> n;

		vector<char> buildings;
		for(i=0; i<n; ++i)
		{
			cin >> j;
			buildings.push_back(j);
		}

		for(i=0; i<n; ++i)
		{
			if(buildings[i]=='1')
			{
				buildings[i] = 'X';
				if( (i-1)>=0 && buildings[i-1]=='0')
					buildings[i-1] = 'X';
				if( (i+1)<n && buildings[i+1]=='0')
					buildings[i+1] = 'X';
			}
		}

		k=0;
		for(i=0; i<n; ++i)
		{
			if(buildings[i]=='0')
				k++;
		}

		cout << k << endl;
	}

	return 0;
}