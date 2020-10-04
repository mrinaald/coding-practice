#include<iostream>
using namespace std;

void pattern(int l, int c);

int main()
{
	int t, l, c;
	
	cin>>t;
	
	for(int i=0; i<t; ++i)
	{
		cin>>l>>c;
		pattern(l, c);
		cout<<endl;
	}
	
	return 0;
}

void pattern(int l, int c)
{
	for(int i=0; i<l; ++i)
	{
		for(int j=0; j<c; ++j)
			if( (i+j)%2 == 0 )
				cout<<'*';
			else
				cout<<'.';
		cout<<endl;
	}
	return;
}
