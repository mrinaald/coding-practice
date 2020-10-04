#include<iostream>
using namespace std;

void pattern(short int l, short int c);

int main()
{
	short int t,l,c;
	
	cin>>t;
	for(short int i=0; i<t; ++i)
	{
		cin>>l>>c;
		pattern(l,c);
		cout<<endl;
	}
	return 0;
}

void pattern(short int l, short int c)
{
	for(short i=0; i<l; ++i)
	{
		for(short j=0; j<c; ++j)
			if( i==0 || j==0 || i==(l-1) || j==(c-1) )
				cout<<'*';
			else
				cout<<'.';
		cout<<endl;
	}
	return;
}
