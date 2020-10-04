#include <iostream>

using namespace std;

unsigned long int max(unsigned long int a, unsigned long int b);

int main()
{
	std::ios::sync_with_stdio(false);

	short input[100][100], n, rows, i, j, k;
	unsigned long int sum[100][100];

	cin >> n;

	for( i=0; i<n; ++i )
	{
		cin >> rows;

		for( j=0; j<rows; ++j)
			for( k=0; k<=j; ++k)
				cin >> input[j][k];

		for( j=0; j<=(rows-1); ++j )
			sum[rows-1][j] = input[rows-1][j];

		for( j=(rows-2); j>=0; --j )
			for( k=0; k<=j; ++k )
				sum[j][k] = input[j][k] + max(sum[j+1][k], sum[j+1][k+1]);

		cout << sum[0][0] << endl;
	}

	return 0;
}

unsigned long int max(unsigned long int a, unsigned long int b)
{
	return (a>b)?a:b;
}