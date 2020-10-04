#include <iostream>

using namespace std;

unsigned long long int** lognFib(unsigned long long int **arr, int n);
unsigned long long int** multiply(unsigned long long int** a1, unsigned long long int** a2);

int main()
{
	int n;
	cin >> n;

	unsigned long long int ** res;
	unsigned long long int** arr;
	arr = new unsigned long long int* [2];
		
	arr[0] = new unsigned long long int [2];
	arr[1] = new unsigned long long int [2];

	arr[0][0] = arr[0][1] = arr[1][0] = 1;
	arr[1][1] = 0;

	if(n==1)
		cout << '0' << '\n';
	else if(n==2)
		{
			cout << '1' << '\n';
		}
		else
		{
			res = lognFib(arr, n-2);

			cout << res[0][0] << '\n';
		}
	return 0;
}

unsigned long long int** lognFib(unsigned long long int **arr, int n)
{
	if(n==1)
		return arr;
	else
	{
		unsigned long long int** temp;
		temp = new unsigned long long int* [2];
		
		temp[0] = new unsigned long long int [2];
		temp[1] = new unsigned long long int [2];

		temp = lognFib(arr, n/2);

		temp = multiply(temp, temp);
		if(n%2)
			temp = multiply(temp, arr);

		return temp;
	}
}

unsigned long long int** multiply(unsigned long long int** a1, unsigned long long int** a2)
{
	unsigned long long int** result;
	result = new unsigned long long int* [2];

	result[0] = new unsigned long long int [2];
	result[1] = new unsigned long long int [2];

	result[0][0] = (a1[0][0] * a2[0][0]) + (a1[0][1] * a2[1][0]);
	result[0][1] = (a1[0][0] * a2[0][1]) + (a1[0][1] * a2[1][1]);
	result[1][0] = (a1[1][0] * a2[0][0]) + (a1[1][1] * a2[1][0]);
	result[1][1] = (a1[1][0] * a2[0][1]) + (a1[1][1] * a2[1][1]);

	return result;
}