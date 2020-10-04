#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	short X;
	float Y;

	cin >> X >> Y;
	cout << std::fixed ;
	cout << setprecision(2);
	if( X%5 == 0)
		{
			if( (X+0.5) <= Y )
				cout << ( Y - X - 0.50);
			else
				cout << Y;
		}
	else
		cout << Y;
	return 0;
}