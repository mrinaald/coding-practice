#include <iostream>

using namespace std;

int main()
{
	short T, N;
	char gest[1050];
	char a;

	cin >> T;

	for( short i=0; i<T; ++i)
	{
		cin >> N;
		a='s';

		for(short j=0; j<N; ++j)
		{
			cin >> gest[j];

			if( a == 's' )
			{
				switch(gest[j])
				{
					case 'I' : a='i'; break;
					case 'Y' : a='n'; break;
				}				
			}
		}

		switch(a)
		{
			case 'i' : cout << "INDIAN\n";
						break;
			case 'n' : cout << "NOT INDIAN\n";
						break;
			case 's' : cout << "NOT SURE\n";
		}
	}
}