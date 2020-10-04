#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int t, n;

	cin >> t;
	while(t--)
	{
		cin >> n;
		int arr[1000];
		bool count[1000];

		for(int i=0; i<1000; ++i)
			count[i]=false;

		for(int i=0; i<(n-1); ++i)
		{
			cin >> arr[i];
			count[arr[i]-1] = true;
		}

		for(int i=0; i<n; ++i)
			if(count[i]==false)
				cout << i+1 << endl;
	}
	return 0;
}