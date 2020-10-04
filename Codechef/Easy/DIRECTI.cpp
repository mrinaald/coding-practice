#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, j, k;
	string str;
	int len;
	string dir, temp;

	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> ws;

		vector<string> directions;
		for(i=0; i<n; ++i)
		{
			getline(cin, str);
			directions.push_back(str);
		}

		switch(directions[n-1][0])
		{
			case 'L'	:	dir = "Right";
							len = 4;
							break;
			case 'R'	:	dir = "Left";
							len = 5;
							break;
			case 'B'	:	dir = "Begin";
							len = 5;
							break;
		}

		directions[n-1].replace(0, len, "Begin");

		for(i=n-2; i>=0; --i)
		{
			switch(directions[i][0])
			{
				case 'L'	:	temp = "Right";
								len = 4;
								break;
				case 'R'	:	temp = "Left";
								len = 5;
								break;
				case 'B'	:	temp = "Begin";
								len = 5;
								break;
			}

			directions[i].replace(0,len,dir);
			dir = temp;
		}

		for(i=n-1; i>=0; --i)
		{
			cout << directions[i] << endl;
		}
	}

	return 0;
}