#include <iostream>

using namespace std;

int main()
{
	int t, n;

	cin >> t;

	while(t--)
	{
		cin >> n;
		int i=1;
		int count=0;
		for(; count<n; count++)
		{
			cout << i << ' ';
			i += 2;
		}
		cout << endl;
	}
	return 0;
}
