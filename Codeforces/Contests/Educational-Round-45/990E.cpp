#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, k;
	int i, j, p;

	cin >> n >> m >> k;

	vector<int> costs(k, 0);
	vector<int> stops(m, 0);

	int gap = 0;
	int max_gap = -1;
	cin >> stops[0];
	for(i=1; i<m; ++i){
		cin >> stops[i];
		if((stops[i]-stops[i-1]) == 1)
			gap++;
		else{
			gap++;
			if(gap > max_gap)
				max_gap = gap;
			gap = 0;
		}
	}
	gap++;
	if(gap > max_gap)
		max_gap = gap;

	for(i=0; i<k; ++i){
		cin >> costs[i];
	}

	if(max_gap >= k){
		cout << -1 << endl;
		return 0;
	}
	if(stops[0] == 0){
		cout << -1 << endl;
		return 0;
	}

	// vector<int> valid;
	// j = 0;
	// for(i=0; i<n; ){
	//     if(i!=stops[j]){
	//         valid.pb(i);
	//         i++;
	//     }
	//     else{
	//         i++;
	//         j++;
	//     }
	// }

	j = 0;
	llong min_cost = 10000000000000000;
	llong curr_cost;
	bool flag = true;
	for(i=max_gap; i<k; ++i){
		p = 0;
		j = 0;
		curr_cost = 0;
		flag = true;
		while(j<n){
			j += (i+1);
			while(stops[p] < j)
				p++;
			if(stops[p] == j){
				flag = false;
				break;
			}
			curr_cost += costs[i];
		}

		if(flag){
			if(curr_cost < min_cost)
				min_cost = curr_cost;
		}
	}

	cout << min_cost << endl;

	return 0;
}
