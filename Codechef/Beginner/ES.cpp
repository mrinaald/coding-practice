#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
	double e = exp(1);
	//cout << pow(10,4000) << '\n';
	unsigned long long int sum=0;
	for(unsigned long long int i=1; i<100; ++i)
	{
		sum += floor(i*e);
		//cout << sum << ' ';
		cout << floor(i*e) << ' ';
		if(i%10==0)
			cout << '\n';
	}

}
