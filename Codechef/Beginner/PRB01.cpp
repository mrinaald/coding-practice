#include <iostream>
#include <cstdio>

using namespace std;

#define SIZE 100000

int se[SIZE];
void prep_se();

int main()
{
	prep_se();
	
	int t, n;

	cin >> t;

	while(t--)
	{
		cin >> n;

		cout << ((se[n-1])?"yes\n":"no\n");
	}

	return 0;
}

void prep_se()
{
	for(int i=0; i<SIZE; ++i)
		se[i]=1;

	se[0] = 0;

	for(int i=1; i<SIZE; ++i)
	{
		if(se[i]==0)
			continue;

		int num = i+1;
		for(int n = num+num; n<=SIZE; n +=num)
			se[n-1] = 0;

	}
}