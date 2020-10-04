#include <iostream>

#define SIZE 50

using namespace std;

void recipe(int arr[], short n);
short HCF(int a, int b);

int main()
{
	short T, N;
	int arr[SIZE];
	int min;
	cin >> T;

	for(short i=0; i<T; ++i)
	{
		cin >> N;
		for(short j=0; j<N; j++)
		{
			cin >> arr[j];
		}

		recipe(arr, N);
	}
	return 0;
}

void recipe(int arr[], short n)
{
	short hcf = HCF(arr[0], arr[1]);
	short i;

	for(i=0; i<n; ++i)
		hcf = HCF(hcf, arr[i]);

	for(i=0; i<n; ++i)
		cout << (arr[i])/hcf << ' ';

	cout << endl;
	return;
}

short HCF(int a, int b)
{
	if( b==0 )
		return a;

	if(a > b)
	{
		int temp = b;
		b=a;
		a=temp;
	}

	return HCF(a, b%a);
}