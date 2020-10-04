#include <iostream>

using namespace std;

int maximize(int a, int b, int c);
int maximize(int a, int b);

int main()
{
	std::ios::sync_with_stdio(false);
	
	short T;
	int A, B, C;
	
	cin >> T;
	
	for(short i=0; i<T; ++i)
	{
		cin >> A >> B >> C;
		cout << maximize(A,B,C) << endl;
	}
	
	return 0;
}

int maximize(int a, int b, int c)
{
	if(a>b)
	{
		if(a>c)
			return maximize(b,c);
		else
			return maximize(a,b);
	}
	else
	{
		if(b>c)
			return maximize(a,c);
		else
			return maximize(a, b);
	}
}

int maximize(int a, int b)
{
	return (a>b)?a:b;
}
