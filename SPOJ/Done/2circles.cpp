#include<iostream>
#include<math.h>
using namespace std;

void check(int x1, int y1, int r1, int x2, int y2, int r2);

int main()
{
	int t;
	int x1, y1, r1, x2, y2, r2;
	
	cin>>t;
	
	for(int i=0; i<t; ++i)
	{
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		
		if(r1>=r2)
			check(x1, y1, r1, x2, y2, r2);
		else
			check(x2, y2, r2, x1, y1, r1);
		cout<<endl;
	}
	return 0;
}

void check(int x1, int y1, int r1, int x2, int y2, int r2)
{
	float dist = sqrt( pow(x1-x2,2) + pow(y1-y2,2));
	
	if( r1 > (dist+r2) )
		cout<<'I';
	else if( r1 == (dist+r2) )
		cout<<'E';
		else
		cout<<'O';
	
	return;
}
