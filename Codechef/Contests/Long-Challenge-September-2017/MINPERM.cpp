#include <iostream>
#include <vector>

using namespace std;

void MINPERM(vector<int> &A);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	cin >> t;

	while(t--)
	{
		cin >> n;

		vector<int> arr;
		for(int i=0; i<n; ++i)
			arr.push_back(i);

		MINPERM(arr);

		for(int i=0; i<n; ++i)
			cout << arr[i]+1 << ' ';
		cout << endl;
	}

	return 0;
}

void MINPERM(vector<int> &A)
{
	int n = A.size();

	int temp;
	int i=0;
	while(i<n)
	{
		if( (i+1)<n )
		{
			temp = A[i];
			A[i] = A[i+1];
			A[i+1] = temp;
			i += 2;
		}
		else
		{
			temp = A[i];
			A[i] = A[i-1];
			A[i-1] = temp;
			i += 1;
		}
	}
}