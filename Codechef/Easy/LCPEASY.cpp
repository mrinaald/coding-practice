#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t;
	char ch;
	int i, j, k;
	int count;

	cin >> t;
	// cin >> ws;
	
	while(t--)
	{
		string str1, str2;
		cin >> str1;
		cin >> str2;

		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		i=0;
		j=0;
		count = 0;
		while( (i<str1.size()) && (j<str2.size()) )
		{
			if(str1[i] == str2[j])
			{
				count++;
				i++;
				j++;
			}
			else if(str1[i] < str2[j])
			{
				i++;
			}
			else
				j++;
		}

		cout << count << endl;
	}

	return 0;
}