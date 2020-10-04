#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, g, i, q;

	cin >> t;
	while(t--)
	{
		cin >> g;
		while(g--)
		{
			cin >> i >> n >> q;

			int ans = n/2;

			if(n%2==0)
				cout << ans;
			else if(i==q)
				cout << ans;
				else
					cout << ans+1;

			cout << endl;
		}
	}

	return 0;
}