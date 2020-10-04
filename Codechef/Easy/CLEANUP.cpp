#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, i, j;
	int n, m;
	int temp;
	bool flag = true;

	cin >> t;

	while(t--)
	{
		cin >> n >> m;

		vector<int> done;
		
		for(i=0; i<m; ++i)
		{
			cin >> temp;
			done.push_back(temp);
		}

		if(done.size()>0)
			sort(done.begin(), done.end());

		vector<int> chef;
		vector<int> ast;

		i=1;
		j=0;
		flag = true;
		while(i<=n)
		{
			if( (done.size()>0) && (i==done[j]) )
			{
				i++;
				j++;
			}
			else if(flag)
			{
				chef.push_back(i);
				i++;
				flag = !flag;
			}
			else
			{
				ast.push_back(i);
				i++;
				flag = !flag;
			}
		}

		for(i=0; i<chef.size(); ++i)
			cout << chef[i] << ' ';
		cout << endl;

		for(i=0; i<ast.size(); ++i)
			cout << ast[i] << ' ';
		cout << endl;
	}

	return 0;
}