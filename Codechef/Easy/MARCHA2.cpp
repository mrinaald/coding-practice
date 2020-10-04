#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPossible(const vector<int> &leaves);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, i, j, k;

	cin >> t;
	while(t--)
	{
		vector<int> leaves;

		cin >> n;

		for(i=0; i<n; ++i)
		{
			cin >> j;
			leaves.push_back(j);
		}

		if(isPossible(leaves))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}

bool isPossible(const vector<int> &leaves)
{
	int n = leaves.size();

	bool completed = false;
	int i, j, k;
	j = 1;
	for(i=0; i<n; ++i)
	{
		if(completed)
			return false;
		
		if(leaves[i] <= j)
		{
			k = j - leaves[i];
			j = 2*k;
			if(k==0)
				completed = true;
		}
		else
			return false;
	}

	return k==0;
}