#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int N, Q, X, num, i;
	vector<int> v;

	cin >> N;
	for(i=0; i<N; ++i)
	{
		cin >> X;
		v.push_back(X);
	}

	cin >> Q;

	for(i=0; i<Q; ++i)
	{
		cin >> X;
		// for using the "auto" type, compile using the option -std=c++11
		// auto  lower = lower_bound(v.begin(), v.end(), X);
		vector<int>::iterator  lower = lower_bound(v.begin(), v.end(), X);
		num = *lower;

		if( num == X )
			cout << "Yes " << distance(v.begin(), lower)+1 << '\n';
		else
			cout << "No " << distance(v.begin(), lower)+1 << '\n';
	}
	
	return 0;
}