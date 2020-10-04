#include<iostream>
using namespace std;

void pattern(short l, short c, short h, short w);

int main()
{
	short t, l, c, h, w;
	
	cin>>t;
	
	for(short i=0; i<t; ++i)
	{
		cin>>l>>c>>h>>w;
		pattern(l,c,h,w);
		cout<<endl;
	}
	return 0;
}

void pattern(short l, short c, short h, short w)
{
	h++;
	w++;
	l *= h;
	c *= w;
	for(short i=0; i<=l; ++i)
	{
		for( short j=0; j<=c; ++j)
			if( i%h ==0 || j%w == 0 )
				cout<<'*';
			else
				cout<<'.';
		cout<<endl;
	}
	return;
}
