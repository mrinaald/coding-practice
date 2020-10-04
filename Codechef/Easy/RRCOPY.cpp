#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, i, j;

	cin >> t;
	while(t--)
	{
		cin >> n;

		vector<int> obtained;
		vector<int> given;
		vector<int> count(100000, 0);

		for(i=0; i<n; ++i)
		{
			cin >> j;
			obtained.push_back(j);
			
			if(count[j-1]==0)
			{
				given.push_back(j);
			}

			count[j-1]++;
		}

		cout << given.size() << endl;
	}

	return 0;
}