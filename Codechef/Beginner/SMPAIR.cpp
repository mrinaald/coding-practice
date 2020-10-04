#include <iostream>

using namespace std;

#define SIZE 100000

void initialize(int arr[], int n);
int sumPair(int arr[], int n);

int main()
{
	std::ios::sync_with_stdio(false);
	
	int T, N;
	int arr[SIZE];
	
	cin >> T;
	
	for(int i=0; i<T; ++i)
	{
		cin >> N;
		
		initialize(arr, N);
		
		for(int j=0; j<N; ++j)
			cin >> arr[j];
		
		cout << sumPair(arr, N) << endl;
	}
	
	return 0;
}

void initialize(int arr[], int n)
{
	for(int i=0; i<n; ++i)
		arr[i]=0;
	
	return;
}

int sumPair(int arr[], int n)
{
	int small1, small2;
	small1 = arr[0];
	small2 = arr[1];
	
	if(small1 > small2)
	{
		int temp = small2;
		small2 = small1;
		small1 = temp;
	}
	
	for(int i=2; i<n; ++i)
	{
		if(small1 > arr[i])
		{
			small2 = small1;
			small1 = arr[i];
		}
		else if(small2 > arr[i])
			{
				small2 = arr[i];
			}
	}
	
	return small1+small2;
}
