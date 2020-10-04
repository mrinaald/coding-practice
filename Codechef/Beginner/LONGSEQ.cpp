#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	short zero, one;
	string digits;

	cin >> t;

	for( int i=0; i<t; ++i)
	{
		digits.clear();
		zero = one = 0;
		cin >> digits;

		n = digits.length();

		for( int j=0; j<n; ++j)
		{
			if( digits[j] == '1')
				one++;
			if( one > 1 )
				break;
		}

		for(int k=0; k<n; ++k)
		{
			if( digits[k] == '0')
				zero++;
			if( zero > 1)
				break;
		}

		if( n > 2 )
		{
			if( zero==0 || one ==0 || zero==one)
					cout << "No\n";
				else
					cout << "Yes\n";
		}
		else
		{
			/*
			0		y
			1		y
			00		n
			01		y
			11		n
			10		y
			*/

			if( zero ==2 || one==2)
				cout << "No\n";
			else
				cout << "Yes\n";
		}

		// cout << endl << digits << endl;
		// cout << endl << digits.length() << endl;
		// cout << endl << digits.capacity() << endl;
		// cout << endl << digits.max_size();
	}
	return 0;
}