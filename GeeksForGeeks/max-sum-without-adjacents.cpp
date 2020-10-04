#include <iostream>

long int sumWithoutAdj(int arr[], int comp[], int n, int curr);

using namespace std;

int main()
{
	int t, n;
	int arr[100];
	int comp[100];

	cin >> t;
	while(t--)
	{
		cin >> n;

		for(int i=0; i<n; ++i)
		{
			cin >> arr[i];
			comp[i] = -1;
		}

		cout << sumWithoutAdj(arr, comp, n, 0) << endl;
	}
	return 0;
}

long int sumWithoutAdj(int arr[], int comp[], int n, int curr)
{
	if(curr >= n)
		return 0;

	if(comp[curr] > 0)
		return comp[curr];

	long long int sum1 = arr[curr] + sumWithoutAdj(arr, comp, n, curr+2);

	long long int sum2 = 0;
	if(curr != (n-1))
	{
		sum2 = arr[curr+1] + sumWithoutAdj(arr, comp, n, curr+3);

		comp[curr] = (sum1>sum2)?sum1:sum2;
	}
	else
		comp[curr] = sum1;

	return comp[curr];
}

// long int sumWithoutAdj(int arr[], int comp[], int n, int curr)
// {
// 	if(curr >= n)
// 		return 0;
	
// 	long int sum1 = arr[curr] + sumWithoutAdj(arr, comp, n, curr+2);

// 	long int sum2 = 0;
// 	if(curr != (n-1))
// 		sum2 = arr[curr+1] + sumWithoutAdj(arr, comp, n, curr+3);

// 	return (sum1>sum2)?sum1:sum2;
// }