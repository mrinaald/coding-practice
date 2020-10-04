#include <iostream>
#include <stdlib.h>

using namespace std;

int digitSum(int n);

int main()
{
	std::ios::sync_with_stdio(false);

	short T, i;
	int N;

	cin >> T;

	for(i=0; i<T; ++i)
	{
		cin >> N;
		cout << digitSum(N) << endl;
	}

	return 0;
}

int digitSum(int n)
{
	int sum=0;

	n = abs(n);
	
	while(n)
	{
		sum += (n%10);
		n /= 10;
	}

	return sum;
}