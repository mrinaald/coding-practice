#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, i, j;
	int n, k;

	cin >> t;

	while(t--)
	{
		cin >> n;

		vector<int> arr;

		for(i=0; i<n; ++i)
		{
			cin >> j;
			arr.push_back(j);
		}

		cin >> k;
		k = arr[k-1];

		i=0;
		int count=0;

		while(i<n)
			if(arr[i++] < k)
				count++;

		cout << count+1 << endl;
	}

	return 0;
}