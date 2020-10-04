#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	unsigned int T, N, i,j , count=0;
	int k;
	cin >> T;

	for(i=0; i<T; ++i)
	{
		cin >> N;
		count = 0;
		for( j=5, k=1; j <=N; j = pow(5, ++k))
		{
			count += N/j;
		}
		cout << count << endl;
	}
	return 0;
}