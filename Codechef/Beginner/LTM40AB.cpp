#include <iostream>

using namespace std;

unsigned long long int solve( unsigned long int a, unsigned long int b, unsigned long int c, unsigned long int d);

int main()
{
	short t;
	unsigned long int a, b, c, d;

	cin >> t;

	for( short i=0; i<t; ++i)
	{
		cin >> a >> b >> c >> d;
		cout << solve(a,b,c,d) << endl;
	}
	return 0;
}

unsigned long long int solve( unsigned long int a, unsigned long int b, unsigned long int c, unsigned long int d)
{
	unsigned long int x = a;
	unsigned long int y = c; 
	unsigned long long int count = 0;
	unsigned long long int x_count = 0;

	for( ; y <= d; ++y)
	{
		count += x_count;

		// x=a;
		while( (x<y) && (x<=b) )
		{
			x++;
			x_count++;
			count++;
		}
	}

	return count;
}