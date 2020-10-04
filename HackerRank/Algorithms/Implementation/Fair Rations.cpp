#include <iostream>
#include <vector>

using namespace std;

void fair_ration(vector<int> bread, int n)
{
	int i;
	int count=0;
	vector<int> temp(n);
	
	for(i=0, temp=bread; i<n-1; ++i)
	{
		if(temp[i]%2)
		{
			temp[i]++;// = bread[i]+1;
			temp[i+1]++;// = bread[i+1]+1;
			count+=2;
		}
	}

	if(temp[n-1]%2)
	{
		count=0;
		for(i=n-1, temp=bread; i>=1; --i)
		{
			if(temp[i]%2)
			{
				temp[i]++;// = bread[i]+1;
				temp[i-1]++;// = bread[i-1]+1;
				count+=2;
			}
		}

		if(temp[0]%2)
			cout << "NO" << '\n';
		else
			cout << count << '\n';
	}
	else
	{
		cout << count << '\n';
		return;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int i;
	vector<int> bread(n);
	for(i=0; i<n; ++i)
		cin >> bread[i];

	fair_ration(bread, n);

	return 0;
}