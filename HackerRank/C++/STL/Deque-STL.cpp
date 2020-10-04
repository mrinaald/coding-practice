/*************************************************************************
	Have used vector instead of deque
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printKMax(int arr[], int n, int k);

int main()
{
	std::ios::sync_with_stdio(false);
	int t, k, n, i;
	
	cin >> t;

	while(t--)
	{
		cin >> n >> k;
		int a[n];
		for(i=0; i<n; ++i)	
			cin >> a[i];

		printKMax(a, n, k);
		cout << '\n';
	}
	
	return 0;
}

void printKMax(int arr[], int n, int k)
{
	int i, maxindex, maxvalue;
	vector<int> max;

	maxindex=0;
	maxvalue=arr[0];
	for(i=1; i<k; ++i)
	{
		if( arr[i] > maxvalue )
		{
			maxindex = i;
			maxvalue = arr[i];
		}
	}

	max.push_back(maxvalue);

	int j;

	for(i=1, j=k; j<n; ++i, ++j)
	{
		if( maxindex >= i )
		{
			if( arr[j] > maxvalue )
			{
				maxindex = j;
				maxvalue = arr[j];
			}
		}
		else
		{
			maxindex = i;
			maxvalue = arr[i];
			for(int p=i+1; p<=j; p++)
			{
				if( arr[p] > maxvalue )
				{
					maxindex = p;
					maxvalue = arr[p];
				}
			}
		}

		max.push_back(maxvalue);
	}

	int size = max.size();

	for(i=0; i<(size-1); ++i)
	{
		cout << max[i] << ' ';
	}
	cout << max[i];
	
	return;
}