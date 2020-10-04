#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int n, r;

	cin >> n;

	int *killer = new int[n];
	
	fill(killer, killer+n, 0);		//std::fill( ptr, ptr+length, initial_value)

	for( int i=0; i<n; ++i)
	{
		cin >> r;
		if(r)
		{
			killer[r-1] += 1;
		}
	}

	for( int j=0; j<n; ++j)
	{
		if( !(killer[j]) )
			cout << j+1 << ' ';
	}
	return 0;
}