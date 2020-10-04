#include <iostream>

using namespace std;

int occurencesFour(int n);

int main()
{
	std::ios::sync_with_stdio(false);
	
	int T, N;
	
	cin >> T;
	
	for(int i=0; i<T; i++)
	{
		cin >> N;
		cout << occurencesFour(N) << endl;
	}
	
	return 0;
}

int occurencesFour(int n)
{
	int count=0;
	
	while(n)
	{
		if( (n%10) == 4 )
			count++;
		n /= 10;
	}
	
	return count;
}
