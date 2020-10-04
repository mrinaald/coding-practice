#include<iostream>
using namespace std;

int main()
{
	short unsigned int a, b, i;
	short unsigned int sum=0;
	
	cin>>a>>b;
	
	for( i=a; i<=b; ++i)
		sum += (i*i);
	
	cout<<sum;
	return 0;
}
