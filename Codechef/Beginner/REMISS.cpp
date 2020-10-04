#include <iostream>

using namespace std;

unsigned long int max(unsigned long int a, unsigned long int b);

int main()
{
	short T, i;
	unsigned long int A, B;

	cin >> T;

	for(i=0; i<T; ++i)
	{
		cin >> A >> B;
		cout << max(A, B) << ' ' << (A+B) << endl;
	}

	return 0;
}

unsigned long int max(unsigned long int a, unsigned long int b)
{
	return (a>b)?a:b;
}