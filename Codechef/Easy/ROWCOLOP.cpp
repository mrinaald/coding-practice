#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int n, q, i, j, k;
	string op;
	long long int maximum;

	cin >> n >> q;

	vector<long long int> row(n,0);
	vector<long long int> col(n,0);

	while(q--)
	{
		cin >> op >> j >> k;
		if(op=="RowAdd")
		{
			row[j-1] += k;
			// for(i=0; i<n; ++i)
			// {
			// 	k = row[j-1] + col[i];
			// 	if(k>maximum)
			// 		maximum = k;
			// }
		}
		else if(op=="ColAdd")
		{
			col[j-1] += k;
			// for(i=0; i<n; ++i)
			// {
			// 	k = col[j-1] + row[i];
			// 	if(k>maximum)
			// 		maximum = k;
			// }
		}
	}

	k = row[0];
	j = col[0];
	maximum = j+k;
	for(i=1; i<n; ++i)
	{
		if(row[i]>k)
		{
			k = row[i];
		}
		if(col[i]>j)
		{
			j = col[i];
		}
		maximum = j+k;
	}

	cout << maximum << endl;

	return 0;
}