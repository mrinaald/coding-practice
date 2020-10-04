#include<iostream>

using namespace std;

int main()
{
	short t, n, x, y, ans; 
	int dist, temp;
	
	cin>>t;
	
	for(short i=0; i<t; i++)
	{
		dist=0;
		cin>>n;
		for(short j=1; j<=n; ++j)
		{
			cin>>x>>y;
			temp = (x*x)+(y*y);
			if( temp > dist)
			{
				dist=temp;
				ans = j;
			}
		}
		cout<<"Case "<<i+1<<": "<<ans<<endl;
	}
	
	return 0;
}
