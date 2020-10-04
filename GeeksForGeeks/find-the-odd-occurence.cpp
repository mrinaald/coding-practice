#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int t, n;

	cin >> t;
	while(t--)
	{
		cin >> n;

		int temp;
		map<int,bool> arr;

		for(int i=0; i<n; ++i)
		{
			cin >> temp;
			if( arr.count(temp) == 1)
				arr[temp] = !arr[temp];
			else
				arr.insert(std::pair<int,bool>(temp,false));
		}

		map<int, bool>::iterator it;
		for(it = arr.begin(); it != arr.end(); it++)
		{
			if(!(it->second))
				cout << it->first << endl;
		}
	}
	return 0;
}