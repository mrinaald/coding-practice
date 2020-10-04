#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,m,i, j;
	
	cin>>n;
	vector<int> S(n);
	for( i=0; i<n; ++i)
		cin>>S[i];
	
	cin>>m;
	vector<int> Q(m);
	for(i=0; i<m; ++i)
		cin>>Q[i];
	
	i=j=0;
	while( i<n && j<m)
	{
		if( S[i] < Q[j] )
		{
			cout<<S[i]<<' ';
			i++;
			continue;
		}
		else if( S[i] == Q[j] )
			{
				i++;	j++;	continue;
			}
			else
			{
				j++;	continue;
			}
	}
	
	if( i<n )					//if sequence S is not completely traversed
		for( ; i<n; ++i)
			cout<<S[i]<<' ';
	return 0;
}
