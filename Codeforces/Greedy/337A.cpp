#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, i, temp;
	int minDiff = 100000000;
	vector<int> puzzles;

	cin >> n >> m;

	for(i=0; i<m; ++i){
		cin >> temp;
		puzzles.pb(temp);
	}

	sort(all(puzzles));

	i = n-1;
	for(;i<m; ++i){
		temp = puzzles[i] - puzzles[i-n+1];
		if(temp<minDiff)
			minDiff = temp;
	}

	cout << minDiff << endl;

	return 0;
}
