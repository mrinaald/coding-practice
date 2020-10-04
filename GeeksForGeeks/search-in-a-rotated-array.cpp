#include <iostream>

#define SIZE 100005

using namespace std;

int searchSortedArray(long int arr[], int n, int key);
int findmin(long int arr[], int l, int r, int size);
int BinSearch(long int arr[], int l, int r, int key);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, k;
	long int arr[SIZE];

	cin >> t;

	while(t--)
	{
		cin >> n;

		for(int i=0; i<n; ++i)
			cin >> arr[i];

		cin >> k;

		cout << searchSortedArray(arr, n, k) << endl;
	}

	return 0;
}

int searchSortedArray(long int arr[], int n, int key)
{
	int start_idx = findmin(arr, 0, n-1, n);

	if(key < arr[n-1])
		return BinSearch(arr, start_idx, n-1, key);
	else
		return BinSearch(arr, 0, start_idx-1, key);
	// return arr[start_idx];
}

int findmin(long int arr[], int l, int r, int size)
{
	int mid = (l+r)/2;

	if( (mid==0) || (mid==(size-1)) )
		return mid;

	if( (arr[mid]>arr[mid-1]) && (arr[mid]<arr[mid+1]) )
	{
		if(arr[mid]>arr[0])
			return findmin(arr, mid+1, r, size);
		else
			return findmin(arr, l, mid-1, size);
	}
	else if(arr[mid]<arr[mid-1])
			return mid;
		else
			return mid+1;
}

int BinSearch(long int arr[], int l, int r, int key)
{
	if(l>r)
		return -1;

	int mid = (l+r)/2;
	if(arr[mid]==key) return mid;
	else if(arr[mid]<key) return BinSearch(arr, mid+1, r, key);
		else return BinSearch(arr, l, mid-1, key);
}