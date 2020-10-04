#include<iostream>
#include<stdio.h>

using namespace std;

void halfprint();

int main()
{
	int t;
	char ch;
	
	cin>>t;
	
	ch = getchar();
	
	for(int i=0; i<t; ++i)
	{
		halfprint();
		cout<<endl;
	}
	
	return 0;
}

void halfprint()
{
	char str[200];
	int len, i;
	
	cin.getline(str, 200);
	
	for(len=0; str[len]!='\0'; ++len);
	
	for( i=0; i<(len/2); ++i)
	{
		if( i%2 == 0)
		{
			cout<<str[i];
		}
	}
	
	return;
}
