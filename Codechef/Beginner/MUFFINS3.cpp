#include <iostream>

using namespace std;

int main()
{
	short T;
	int N;
	
	cin >> T;

	for( short i=0; i<T; ++i)
	{
		cin >> N;

		cout << ( (N/2) + 1) << endl;
	}

	return 0;
}