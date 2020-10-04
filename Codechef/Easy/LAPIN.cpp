#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, len, mid, i;
	string str;
	bool flag;

	cin >> t;

	while(t--)
	{
		cin >> str;

		len = str.length();

		vector<int> freq(26, 0);

		mid = len/2;
		i=0;
		for(; i<mid; ++i)
			freq[ str[i]-'a' ]++;

		i = i + (len%2);

		for(; i<len; ++i)
			freq[ str[i]-'a' ]--;

		flag = true;
		for(i=0; i<26; ++i)
			if(freq[i] != 0)
			{
				flag = false;
				break;
			}

		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}