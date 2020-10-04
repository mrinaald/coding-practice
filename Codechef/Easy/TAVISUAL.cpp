#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, q, l, r, c;

	cin >> t;
	while(t--)
	{
		cin >> n >> c >> q;

		while(q--)
		{
			cin >> l >> r;
			if( (l<=c) && (c<=r) )
			{
				c = abs(r+l-c);
			}
		}

		cout << c << endl;
	}

	return 0;
}