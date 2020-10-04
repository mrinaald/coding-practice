#include <iostream>
#include <vector>

#define MAX_SIZE 100000

using namespace std;

vector<long long int> arr;

long long int maxDollars(long long int n);
long long int max(long long int a, long long int b);

int main()
{
	std::ios::sync_with_stdio(false);

	long long int n;

	while(cin>>n)
	{
		if(n>MAX_SIZE)
			arr.resize(MAX_SIZE+1, -1);
		else
			arr.resize(n+1, -1);

		arr[0]=0;
		cout << maxDollars(n) << endl;
	}
	return 0;
}

long long int maxDollars(long long int n)
{
	if(n>MAX_SIZE)
		return max(n, maxDollars(n/2) + maxDollars(n/3) + maxDollars(n/4));

	if(arr[n]!= -1)
		return arr[n];

	arr[n] = max(n, maxDollars(n/2) + maxDollars(n/3) + maxDollars(n/4));

	return arr[n];
}

long long int max(long long int a, long long int b)
{
	return (a>b)?a:b;
}