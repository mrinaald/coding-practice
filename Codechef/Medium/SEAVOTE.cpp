#include <iostream>
#include <vector>
#include <string>

using namespace std;

string isStatsValid(vector<int> &stats);
int max(int a, int b){
	return (a>b)?a:b;
}

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, temp;

	cin >> t;
	while(t--){
		cin >> n;

		vector<int> stats;
		for(i=0; i<n; ++i){
			cin >> temp;
			stats.push_back(temp);
		}

		cout << isStatsValid(stats) << endl;
	}

	return 0;
}

string isStatsValid(vector<int> &stats){
	int i, j;
	int sumUpper = 0, sumLower = 0;
	int n = stats.size();

	for(i=0; i<n; ++i){
		sumUpper += stats[i];

		// percentile cannot be negative, nd stats might contain 0
		sumLower += max(0,(stats[i]-1));
	}

	if( (sumUpper >= 100) && (sumLower < 100)){
		return "YES";
	}
	else{
		return "NO";
	}

}