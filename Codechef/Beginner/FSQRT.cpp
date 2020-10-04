#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	short T;
	int N;
	
	cin >> T;
	
	for(short i=0; i<T; ++i)
	{
		cin >> N;
		cout << (int)sqrt(N) << endl;
	}
	
	return 0;
}
