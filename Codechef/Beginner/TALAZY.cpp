#include <iostream>

using namespace std;

unsigned long long int total_time(unsigned long long int n, unsigned long long int b, unsigned long long int m);

int main()
{
	std::ios::sync_with_stdio(false);

	unsigned int t;
	unsigned long long int n, b, m;

	cin >> t;

	for( unsigned int i=0; i<t; ++i)
	{
		cin >> n >> b >> m;
		cout << total_time(n, b, m) << endl;
	}
	return 0;
}

unsigned long long int total_time(unsigned long long int n, unsigned long long int b, unsigned long long int m)
{
	if( n==1 )
	{
		return m;
	}

	unsigned long long int todo, time_todo;

	if( n%2 == 0)
		todo = n/2;
	else
		todo = (n+1)/2;

	time_todo = (todo*m) + b;

	return (time_todo + total_time( n-todo, b, 2*m) );
}