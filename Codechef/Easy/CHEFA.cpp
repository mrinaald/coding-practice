/********************************************************************
// ADD operation for BigInteger is implemented
********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long int ullong;

void addInt(vector<char> &ans, string str);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, j, k;

	cin >> t;
	while(t--)
	{
		cin >> n;

		vector<int> piles;
		vector<ullong> chef;
		ullong score = 0;
		ullong extra = 0;

		for(i=0; i<n; ++i)
		{
			cin >> j;
			piles.push_back(j);
		}

		sort(piles.begin(), piles.end());

		for(i=n-1; i>=0; i-=2)
		{
			extra = piles[i];
			if((score+extra) > score)
				score += extra;
			else
			{
				chef.push_back(score);
				score = extra;
			}
		}

		chef.push_back(score);

		vector<char> answer(15,'0');

		for(i=0; i<chef.size(); ++i)
		{
			string str = to_string(chef[i]);
			addInt(answer, str);
		}

		i=0;
		while( (i<15) && (answer[i]=='0') )
			i++;

		for(;i<15; ++i)
			cout << answer[i];

		cout << endl;
	}

	return 0;
}

void addInt(vector<char> &ans, string str)
{
	int i, j, k;
	char ch;
	int carry = 0;
	int n = str.length();

	i = n-1;
	j = ans.size()-1;

	for(; i>=0 && j>=0; i--,j--)
	{
		// ch = ( (a-'0') + (b-'0') ) + '0';
		ch = str[i] + ans[j] - '0' + (carry==1);

		if(ch>'9')
		{
			ch = (ch - '9') + '0';
			ch--;
			carry = 1;
		}
		else
			carry = 0;

		ans[j] = ch;
	}

	if(carry==1)
	{
		for(;j>=0;j--)
		{
			ch = ans[j] + (carry==1);
			if(ch>'9')
			{
				ch = (ch - '9') + '0';
				ch--;
				carry = 1;
				ans[j] = ch;
			}
			else
			{
				ans[j] = ch;
				break;
			}
		}
	}
}