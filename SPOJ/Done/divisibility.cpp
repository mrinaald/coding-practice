#include<iostream>
using namespace std;

int main()
{
	int t;
	int i, n, x, y;
	
	cin>>t;
	
	for(int j=0; j<t; ++j)
	{
		cin>>n>>x>>y;
			
		for( i=2; i<n; ++i)
		{
			if( i%x == 0 && i%y != 0 )
				cout<<i<<' ';
		}
	}
	return 0;
}
