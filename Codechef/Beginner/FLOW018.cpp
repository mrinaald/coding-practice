#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
	std::ios::sync_with_stdio(false);
	
	int T, N;
	
	cin >> T;
	
	for(int i=0; i<T; ++i)
	{
		cin >> N;
		
		cout << factorial(N) << endl;
		
	}
	return 0;
}

int factorial(int n)
{
	int ans=1;
	for(int i=1; i<=n; ++i)
		ans *= i;
	return ans;
}
