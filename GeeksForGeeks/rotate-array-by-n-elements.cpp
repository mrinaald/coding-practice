#include <iostream>

using namespace std;

int main()
{
	int t, n, d;
	int arr[100];

	cin >> t;

	while(t--)
	{
		cin >> n >> d;
		for(int i=0; i<n; ++i)
			cin >> arr[i];

		for(int i=d; i<n; ++i)
			cout << arr[i] << ' ';

		for(int i=0; i<d; ++i)
			cout << arr[i] << ' ';
		cout << endl;
	}
	return 0;
}