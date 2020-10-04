#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;
vector<long long int> dp;

long long int ACODE(int n);

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> str;

	while(str!="0")
	{
		int n = str.length();
		dp.clear();
		dp.resize(n, -1);

		cout << ACODE(n-1) << endl;
		cin >> str;
	}

	return 0;
}

long long int ACODE(int n)
{
	// if(n<0)
	// 	return 0;
	
	if(dp[n]!=-1)
		return dp[n];

	if(n==0)
	{
		dp[n] = (str[n]=='0')?0:1;
		return dp[n];
	}
	if(n==1)
	{
		if(str[n]=='0')
		{
			if( (str[n-1]=='1') || (str[n-1]=='2') )
				dp[n]=1;
			else dp[n]=0;
		}
		else if( str[n-1] == '1' )
				dp[n] = 2;
			else if(str[n-1] == '2')
					{
						if(str[n]<='6')
							dp[n]=2;
						else
							dp[n]=1;
					}
				else
					dp[n] = 1;

		return dp[n];
	}

	if(str[n]=='0')
	{
		if( (str[n-1]=='1') || (str[n-1]=='2') )
			dp[n]=ACODE(n-2);
		else dp[n]=0;
	}
	else if( str[n-1] == '1' )
			dp[n] = ACODE(n-1) + ACODE(n-2);
		else if(str[n-1] == '2')
				{
					if(str[n]<='6')
						dp[n] = ACODE(n-1) + ACODE(n-2);
					else
						dp[n] = ACODE(n-1);
				}
			else
				dp[n] = ACODE(n-1);
	
	return dp[n];
}