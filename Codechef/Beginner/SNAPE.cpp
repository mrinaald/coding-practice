#include <iostream>
#include <math.h>

using namespace std;

void calculate_RS(int b, int l);

int main()
{
	int T, B, LS;

	cin >> T;

	for(int i=0; i<T; ++i)
	{
		cin >> B >> LS;

		calculate_RS(B, LS);
	}

	return 0;
}

void calculate_RS(int b, int l)
{
	int bSq = b*b;
	int lSq = l*l;
	cout << sqrt(lSq - bSq) << ' ' << sqrt(lSq + bSq) << endl;
}