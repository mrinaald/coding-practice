#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t, n;
	cin >> t;

	while(t--)
	{
		cin >> n;
		int temp;
		vector<int> num;

		for(int i=0; i<n; ++i)
		{
			cin >> temp;
			num.push_back(temp);
		}
		for(int i=0; i<n; ++i)
			cout << num[i];
		cout << endl;
	}
	return 0;
}
