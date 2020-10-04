#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, i;
	bool flag = false;
	string str;

	cin >> t;
	while(t--)
	{
		cin >> str;
		flag = false;

		for(i=2; i<(str.length()); ++i)
		{
			if( (str[i-2]=='0') && (str[i-1]=='1') && (str[i]=='0') )
			{
				flag = true;
				break;
			}
			if( (str[i-2]=='1') && (str[i-1]=='0') && (str[i]=='1') )
			{
				flag = true;
				break;
			}
		}

		if(flag)
			cout << "Good\n";
		else
			cout << "Bad\n";
	}

	return 0;
}