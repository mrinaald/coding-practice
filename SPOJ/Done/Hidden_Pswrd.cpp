#include<iostream>
#include<stdio.h>
#include<vector>
#include<bitset>
using namespace std;

void decode(char t[], short &a, short &b);
void answer(char str[], short n);
short power(short a, short b);

vector <short>a;
vector <short>b;

int main()
{
	short t, n;
	char tuple[7], ch;
	char string[65];
	cin>>t;
	
	for(short i=0; i<t; ++i)
	{
		cin>>n;
		
		a.resize(n);
		b.resize(n);
		
		for(short j=0; j<n; ++j)
		{
			ch = getchar();		//for flushing buffer
			cin>>tuple;
			decode( tuple, (a[j]), (b[j]));
		}
		ch = getchar();		//for flushing buffer
		cin>>string;
		answer( string, n);
		cout<<endl;
	}
	return 0;
}

void decode(char t[], short &a, short &b)
{
	short sum_a=0, sum_b=0;
	for(short i=0; i<6; ++i)
	{
		bitset<8> x( (int)(t[i]) );
		
		sum_a += (x[i])*power(2,i);
		sum_b += (x[ (i+3)%6 ])*power(2,i);
	}
	
	a=sum_a;
	b=sum_b;
	
	return;
}

void answer(char str[], short n)
{
	for(short i=0; i<n; ++i)
	{
		cout << str[ (a[i]) ] << str[ (b[i]) ];
	}
	return;
}

short power(short a, short b)
{
	short prod = 1;
	for(short i=0; i<b; ++i)
		prod *= a;
	
	return prod;
}
