#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, k, num, i, min, max;

	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		vector<int> weights;

		for(i=0; i<n; ++i)
		{
			cin >> num;
			weights.push_back(num);
		}

		sort(weights.begin(), weights.end());

		min = max = 0;
		if(k > (n/2))		// the smaller set must have least weights
			k = n-k;		// modifying k to always be less than n/2

		for(i=0; i<(weights.size()); ++i)
		{
			if(i<k)
				min += weights[i];
			else
				max += weights[i];
		}

		cout << abs(max-min) << endl;
	}

	return 0;
}