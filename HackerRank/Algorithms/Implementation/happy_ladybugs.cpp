#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void happy_ladybugs(string str,short n)
{
	if(n==1)
	{
		if( str[0]=='_' )
		{
			cout << "YES" << '\n';
			return;
		}
		else
		{
			cout << "NO" << '\n';
			return;
		}
	}

	vector<short> arr(n);
	short i;
	int flag=0;

	for(i=0; i<n; ++i)
	{
		arr[i] = (int)str[i];
		if( str[i] == '_' )
			flag=1;
	}

	if(flag)
	{
		sort(arr.begin(), arr.end());	//ASCII value of '_' is 95
		
		if( arr[0] != arr[1] )
		{
			cout << "NO" << '\n';
			return;
		}

		while( (n>=1) && (arr[n-1] == (int)'_') )
			n--;

		if( n==0 )
		{
			cout << "YES" << '\n';
			return;
		}

		i=2;
		while( (i<n-1) )
		{
			if( (arr[i] != arr[i-1]) && (arr[i] != arr[i+1]) )
			{
				cout << "NO" << '\n';
				return;
			}
			i++;
		}

		if( arr[n-1] != arr[n-2] )
		{
			cout << "NO" << '\n';
			return;
		}
		else
		{
			cout << "YES" << '\n';
			return;
		}
	}
	else
	{
		if( arr[0] != arr[1] )
		{
			cout << "NO" << '\n';
			return;
		}

		i=2;
		while( (i<n-1) )
		{
			if( (arr[i] != arr[i-1]) && (arr[i] != arr[i+1]) )
			{
				cout << "NO" << '\n';
				return;
			}
			i++;
		}
		
		if( arr[n-1] != arr[n-2] )
		{
			cout << "NO" << '\n';
			return;
		}
		else
		{
			cout << "YES" << '\n';
			return;
		}
	}
}

int main()
{
	short g;
	cin >> g;
	short n;
	string str;
	
	while(g--)
	{
		
		cin >> n;
		cin >> str;
		happy_ladybugs(str,n);
	}

	return 0;
}