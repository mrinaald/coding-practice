#include <iostream>

using namespace std;

#define SIZE 100000

int arr[SIZE];

void start();
void ambigPermute(int arr[], int n);

int main()
{
	start();
	return 0;
}

void start()
{
	int n;

	cin >> n;

	while(n)
	{
		for(int i=0; i<n; ++i)
			cin >> arr[i];

		ambigPermute(arr, n);

		for(int i=0; i<n; ++i)
			arr[i] = 0;

		cin >> n;
	}
	return;
}

void ambigPermute(int arr[], int n)
{
	bool flag = true;

	for(int i=1; i<=n; ++i)
	{
		int j=0;
		while(j<n && arr[j]!=i)
			j++;

		if( arr[i-1] != (j+1) )
		{
			flag = false;
			break;
		}
	}

	if(flag)
		cout << "ambiguous\n";
	else
		cout << "not ambiguous\n";
	return;
}