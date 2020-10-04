#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

vector<vector<llong> > dp;
int N;
vector<int> costs;
vector<string> arr;

llong func(int id, int orient);

int main(){
	std::ios::sync_with_stdio(false);

	int i;

	cin >> N;

	costs.assign(N, 0);
	arr.assign(N, "");
	dp.assign(N, vector<llong>(2, -1));

	for(i=0; i<N; ++i){
		cin >> costs[i];
	}

	for(i=0; i<N; ++i){
		cin >> arr[i];
	}

	llong x = func(N-1, 0);
	llong y = func(N-1, 1);

	if((x==LLONG_MAX) && (y==LLONG_MAX))
		cout << -1 << endl;
	else if(x==LLONG_MAX)
		cout << y << endl;
	else if(y==LLONG_MAX)
		cout << x << endl;
	else
		cout << min(x, y) << endl;

	return 0;
}

llong func(int id, int orient){
	if(id==0){
		if(orient == 0)
			return 0;
		else
			return costs[0];
	}

	if(dp[id][orient] != -1)
		return dp[id][orient];

	string prev_str = arr[id-1];
	string curr_str = arr[id];
	llong x = LLONG_MAX;
	llong y = LLONG_MAX;

	if(orient == 0){
		if(prev_str <= curr_str){
			x = func(id-1, 0);
		}

		reverse(all(prev_str));
		if(prev_str <= curr_str){
			y = func(id-1, 1);
		}

		dp[id][orient] = min(x, y);
	}
	else if(orient == 1){
		reverse(all(curr_str));

		if(prev_str <= curr_str){
			x = func(id-1, 0);
			if(x < LLONG_MAX)
				x += costs[id];
		}

		reverse(all(prev_str));
		if(prev_str <= curr_str){
			y = func(id-1, 1);
			if(y < LLONG_MAX)
				y += costs[id];
		}

		dp[id][orient] = min(x, y);

	}

	return dp[id][orient];
}
