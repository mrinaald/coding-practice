#include<iostream>
using namespace std;

void fruit_trees(short A, short B, short L);
bool is_palin(short n);

int main()
{
	short t, A, B, L;
	
	cin>>t;
	
	for(short i=0; i<t; ++i)
	{
		cin>>A>>B>>L;
		fruit_trees(A, B, L);
		cout<<endl;
	}
	return 0;
}

void fruit_trees(short A, short B, short L)
{
	short count = 0, temp_count = 0;
	short S, E, temp_s, temp_e;
	for(short i=A; i<=B; ++i)
	{
		if( !is_palin(i) )
			continue;
		
		temp_s = temp_e = i;
		temp_count++;
		
		for( short j=(i+1), k=1; ( j<=B && k<L ); ++j, ++k)
		{
			if( !is_palin(j) )
				continue;
			
			temp_e = j;
			temp_count++;
		}
		
		if( temp_count > count )
		{
			count = temp_count;
			S = temp_s;
			E = temp_e;
		}
		temp_count=0;
	}
	
	if( count == 0 )
		cout<<"Barren Land.";
	else
		cout<<S<<' '<<E;
}

bool is_palin(short n)
{
	short num=n;
	short r, d=0;
	
	while(num>0)
	{
		r = num%10;
		d = (d*10)+r;
		num /= 10;
	}
	
	return ( d==n );
}
