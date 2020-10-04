#include <iostream>
#include <vector>

using namespace std;

void printChars(vector<short> digits);

int main()
{
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	cin >> ws;

	while(t--)
	{
		vector<short> digits(10, 0);
		char ch;

		ch = cin.get();
		while(ch != '\n')
		{
			if(digits[ch - '0'] < 2)
				digits[ch - '0']++;
			ch = cin.get();
		}

		printChars(digits);
	}

	return 0;
}

void printChars(vector<short> digits)
{
	int i;
	char ch;

	if(digits[6] > 0)
	{
		for(i=5; i<10; ++i)
		{
			if(digits[i] > 0)
			{
				if(i==6)
				{
					if(digits[i] == 2)
					{
						ch = (char)(60 + i);
						cout << ch;
					}
				}
				else
				{
					ch = (char)(60 + i);
					cout << ch;
				}
			}
		}
	}

	if(digits[7] > 0)
	{
		for(i=0; i<10; ++i)
		{
			if(digits[i] > 0)
			{
				if(i==7)
				{
					if(digits[i] == 2)
					{
						ch = (char)(70 + i);
						cout << ch;
					}
				}
				else
				{
					ch = (char)(70 + i);
					cout << ch;
				}
			}
		}
	}

	if(digits[8] > 0)
	{
		for(i=0; i<10; ++i)
		{
			if(digits[i] > 0)
			{
				if(i==8)
				{
					if(digits[i] == 2)
					{
						ch = (char)(80 + i);
						cout << ch;
					}
				}
				else
				{
					ch = (char)(80 + i);
					cout << ch;
				}
			}
		}
	}

	if((digits[9]>0) && (digits[0]>0))
		cout << 'Z';

	cout << '\n';
}