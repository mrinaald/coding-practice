#include <iostream>

using namespace std;

int main()
{
	int t, n, zeros, ones, twos, temp;

	cin >> t;
	while(t--)
	{
		cin >> n;

		zeros = ones = twos = 0;
		for(int i=0; i<n; ++i)
		{
			cin >> temp;
			switch(temp)
			{
				case 0	:	zeros++; break;
				case 1	: 	ones++; break;
				case 2	:	twos++; break;
			}
		}

		for(int i=0; i<zeros; i++)
			cout << "0 ";
		for(int i=0; i<ones; i++)
			cout << "1 ";
		for(int i=0; i<twos; i++)
			cout << "2 ";
		cout << endl;
	}
	return 0;
}