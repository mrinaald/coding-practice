#include <iostream>
#include <vector>

using namespace std;

int findInversions(vector<int> &arr, int left, int right);
int merge(vector<int> &arr, int left, int right);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, j, k;
	int inv, localInv;

	cin >> t;
	while(t--)
	{
		cin >> n;

		vector<int> A;
		for(i=0; i<n; i++)
		{
			cin >> k;
			A.push_back(k);
		}

		vector<int> tempA(A);

		inv = findInversions(tempA, 0, n-1);
		// for(i=0; i<n; ++i)
		// 	cout << tempA[i] << ' ';
		// cout << endl;

		localInv = 0;
		for(i=0; i<(n-1); ++i)
		{
			if(A[i] > A[i+1])
				localInv++;
		}

		// cout << inv << ' ' << localInv << endl;

		if(inv == localInv)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}

int findInversions(vector<int> &arr, int left, int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		int i1 = findInversions(arr, left, mid);
		int i2 = findInversions(arr, mid+1, right);
		int i3 = merge(arr, left, right);
		return i1+i2+i3;
	}
	else
		return 0;
}

int merge(vector<int> &arr, int left, int right)
{
	int mid = (left+right)/2;
	int inv=0;
	int i, j, k;
	i = left;
	j = mid+1;
	vector<int> tempA;

	while( (i<=mid) && (j<=right) )
	{
		if(arr[i] <= arr[j])
		{
			tempA.push_back(arr[i]);
			i++;
		}
		if(arr[i] > arr[j])
		{
			tempA.push_back(arr[j]);
			j++;
			inv += mid-i+1;
		}
	}
	while(i<=mid)
	{
		tempA.push_back(arr[i]);
		i++;
	}
	while(j<=right)
	{
		tempA.push_back(arr[j]);
		j++;
	}

	for(i=left; i<=right; ++i)
	{
		arr[i] = tempA[i-left];
	}

	return inv;
}