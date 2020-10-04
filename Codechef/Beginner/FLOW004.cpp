#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int T;
	string N;

	short sum=0;

	cin >> T;

	for(int i=0; i<T; ++i)
	{
		cin >> N;
		
		sum = N[0] - '0';

		short j;
		for(j=0; N[j]!='\0'; ++j);

		if(j)
			sum += N[j-1] - '0';
		else
			sum *=2;

		cout << sum << endl;
		sum=0;
	}

	return 0;
}