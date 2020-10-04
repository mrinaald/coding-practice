#include <iostream>
#include <vector>	

using namespace std;

typedef unsigned long long int ullong;

int CHEFSUM(vector<ullong> &A);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	cin >> t;

	while(t--)
	{
		cin >> n;
		
		int i;
		ullong temp;
		vector<ullong> arr;

		for(i=0; i<n; ++i)
		{
			cin >> temp;
			arr.push_back(temp);
		}

		cout << CHEFSUM(arr) << endl;
	} 

	return 0;
}

int CHEFSUM(vector<ullong> &A)
{
	int n = A.size();
	ullong sumL, sumR, minSum;
	int i, j, k;
	int minInd;

	sumL = sumR = 0;
	j = n-1;

	for(i=0; i<n; ++i)
		sumR += A[i];

	i = 0;
	sumL = A[0];
	minSum = sumL+sumR;
	minInd = 0;

	for(i=1; i<n; ++i)
	{
		sumL += A[i];
		sumR -= A[i-1];

		if( (sumL+sumR) < minSum )
		{
			minSum = sumL + sumR;
			minInd = i;
		}
	}

	return minInd+1;
}