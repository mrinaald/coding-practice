#include <iostream>

using namespace std;

int main()
{
	short t;
	int n, notes;

	cin >> t;

	for(short i=0; i<t; ++i)
	{
		notes = 0;
		cin >> n;

		// if( n%100 == 0 )
		// {
		// 	cout << n/100 << endl;
		// 	continue;
		// }
		// else if( n%50 == 0)
		// 	{
		// 		notes = n/100;
		// 		n = n%100;
		// 	}

		notes = n/100;
		n = n%100;
		
		if(n == 0)
		{
			cout << notes << endl;
		}
		else
		{
			notes += n/50;
			n = n%50;

			if( n == 0)
			{
				cout << notes << endl;
			}
			else
			{
				notes += n/10;
				n = n%10;

				if( n == 0)
				{
					cout << notes << endl;
				}
				else
				{
					notes += n/5;
					n = n%5;

					if( n == 0)
					{
						cout << notes << endl;
					}
					else
					{
						notes += n/2;
						n = n%2;

						if( n == 0)
						{
							cout << notes << endl;
						}
						else
						{
							notes += n;
							
							cout << notes << endl;
						}	
					}
				}

			}
		}
	}

	return 0;
}