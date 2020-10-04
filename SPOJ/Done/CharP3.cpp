#include<iostream>
using namespace std;

void pattern(short l, short c);

int main()
{
	short t, l, c;
	
	cin>>t;
	
	for(short i=0; i<t; ++i)
	{
		cin>>l>>c;
		pattern(l, c);
		cout<<endl;
	}
	return 0;
}

void pattern(short l, short c)
{
	l *= 3;
	c *= 3;
	
	for(short i=0; i<=l; ++i)
	{
		for(short j=0; j<=c; ++j)
			if( i%3==0 || j%3 == 0 )
				cout<<'*';
			else
				cout<<'.';
		cout<<endl;
	}
	return;
}
