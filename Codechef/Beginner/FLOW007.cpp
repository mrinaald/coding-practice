#include <iostream>

using namespace std;

int reverseNum(int n);

int main()
{
	std::ios::sync_with_stdio(false);
	
	int T, N;
	
	cin >> T;
	
	for(int i=0; i<T; ++i)
	{
		cin >> N;
		
		cout << reverseNum(N) << endl;
	}
	
	return 0;
}

int reverseNum(int n)
{
	int rev=0;
	int dig=0;
	
	while(n)
	{
		dig = n%10;
		rev = (10*rev) + dig;
		n /= 10;
	}
	
	return rev;
}
