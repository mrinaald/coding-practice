#include <iostream>

using namespace std;

typedef long long int llong;

int main()
{
	std::ios::sync_with_stdio(false);

	int n, num;
	llong sum=0;

	int i;

	cin >> n;

	for(i=0; i<n; ++i)
	{
		cin >> num;
		sum += num;
		sum = sum -(i+1);
	}

	if(sum==0)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}