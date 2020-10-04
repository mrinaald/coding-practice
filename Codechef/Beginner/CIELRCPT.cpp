#include <iostream>

using namespace std;

int receipt(short arr[], int p);

int main()
{
	short arr[12];
	short i;
	arr[0] = 1;

	for(i=1; i<12; ++i)
		arr[i] = 2*(arr[i-1]);

	short T;
	int p;

	cin >> T;

	for(i=0; i<T; ++i)
	{
		cin >> p;
		cout << receipt(arr, p) << endl;
	}
	return 0;
}

int receipt(short arr[], int p)
{
	short i;
	int ans=0;
	
	while(p!=0)
	{
		i=0;
		while( (i<12) && ((arr[i])<=p) )
			i++;

		i--;
		p -= arr[i];
		ans++;
	}
	return ans;
}