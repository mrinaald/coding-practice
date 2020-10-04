#include <iostream>

using namespace std;

int main()
{
	int test;
	unsigned long long int u, v, temp;

	cin >> test;

	while(test--)
	{
		cin >> u >> v;
		temp = u+v+1;
		temp = (temp-1)*temp;
		temp = temp/2;
		temp += 1;
		cout << temp+u << endl;
	}
	return 0;
}
