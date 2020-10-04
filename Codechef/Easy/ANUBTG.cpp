#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool great(const int &a, const int &b)
{
	return a>b;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, j;

	cin >> t;
	while(t--)
	{
		cin >> n;

		vector<int> price;
		long long int bill = 0;

		for(i=0; i<n; ++i)
		{
			cin >> j;
			price.push_back(j);
		}

		sort(price.begin(), price.end(), great);
		for(i=0; i<n; ++i)
		{
			cout << price[i] << ' ';
		}

		i=0;
		while(i<n)
		{
			bill += price[i];
			if((i+1)<n)
				bill += price[i+1];
			i += 4;
		}

		cout << bill << endl;
	}

	return 0;
}