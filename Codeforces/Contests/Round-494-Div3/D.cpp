#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <climits>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;

vector<int> coins;
map<int, int, greater<int> > counts;
int n;
int min_coins = -1;

void func(int num, int c);

int main(){
	std::ios::sync_with_stdio(false);

	int q, i, j;
	bool is_odd = false;
	llong sum = 0;

	cin >> n >> q;

	coins.assign(n, 0);
	for(i=0; i<n; ++i){
		cin >> coins[i];
		sum += coins[i];
		if(counts.find(coins[i]) == counts.end()){
			counts.insert(mp(coins[i], 1));
		}
		else{
			counts[coins[i]] += 1;
		}
		if(coins[i] == 1)
			is_odd = true;
	}

	while(q--){
		cin >> j;

		if((j%2==1) && (is_odd == false)){
			cout << -1 << endl;
			continue;
		}
		if(j > sum){
			cout << -1 << endl;
			continue;
		}

		min_coins = INT_MAX;
		// func(j, 0);

		if(min_coins == INT_MAX)
			cout << -1 << endl;
		else
			cout << min_coins << endl;
	}

	return 0;
}

void func(int num, int c){
	if(num == 0){
		if(c < min_coins){
			min_coins = c;
		}
		return;
	}
	if(num < 0)
		return;
	if(c >= min_coins)
		return;

	map<int, int, greater<int> >::iterator it = counts.begin();

	for(; it != counts.end(); ++it){
		if(it->first > num)
			continue;
		if(it->second > 0){
			it->second -= 1;
			func(num - it->first, c+1);
			it->second += 1;
		}
	}
}
