#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, i, j, k, ans;

	cin >> t;

	while(t--)
	{
		string J, S;

		cin >> J;
		cin >> S;

		tr1::unordered_map<char, int> hash;

		for(i=0; i<(J.length()); ++i)
		{
			if( hash.find(J[i]) != hash.end())
				hash[J[i]]++;
			else
				hash[J[i]] = 1;
		}

		ans = 0;
		for(i=0; i<(S.length()); i++)
		{
			if( hash.find(S[i]) != hash.end() )
			{
				if(hash[S[i]]>0)
				{
					ans++;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}