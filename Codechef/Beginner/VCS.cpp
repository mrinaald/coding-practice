#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int test, n, m, k;
	cin >> test;

	while(test--)
	{
		cin >> n >> m >> k;

		int temp;
		int t=0;
		int u=0;
		vector<bool> a(n,false);
		vector<bool> b(n,false);

		for(int i=0; i<m; ++i)
		{
			cin >> temp;
			a[temp-1]=true;
		}
		for(int i=0; i<k; ++i)
		{
			cin >> temp;
			b[temp-1] = true;
		}

		for(int i=0; i<n; ++i)
		{
			if(a[i] && b[i])
				t++;
			if(!(a[i] || b[i]))
				u++;
		}
		cout << t << ' ' << u << endl;
	}
	return 0;
}
