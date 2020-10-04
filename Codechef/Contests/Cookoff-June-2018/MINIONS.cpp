#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;

struct Minion{
	int a;
	int b;

	Minion(){
		a = b = 0;
	}

	Minion(int aa, int bb){
		a = aa;
		b = bb;
	}
};

bool comparator(const Minion &a, const Minion &b){
	if(a.a < b.a)
		return true;
	else if(a.a == b.a){
		return a.b < b.b;
	}
	else
		return false;
}

llong maxMinions(const vector<Minion> &m, vector<llong> &dp, int i, int curr_min, llong sum, int count);

int main(){
	std::ios::sync_with_stdio(false);

	int T, N, i, j, k, a, b;

	cin >> T;
	while(T--){
		cin >> N;

		vector<Minion> minions(N);
		vector<llong> arr(N, -1);

		for(i=0; i<N; ++i){
			cin >> minions[i].a >> minions[i].b;
		}

		cout << maxMinions(minions, arr, N-1, 1000000000, 0, 0) << endl;

		// double t;
		// int minA;
		// int temp;
		// llong count = 0;
        //
		// for(i=0; i<N; ++i){
		//     minA = minions[i].a;
		//     temp = sumArr[i];
        //
		//     for(j=i; j<N; ++j){
		//         t = ((double)sumArr[j])/(j-i+1);
		//         if(t <= minA){
		//             // cout << t << ' ' << minA << ' ' << i << ' ' << j << endl;
		//             count++;
		//         }
		//         sumArr[j] -= temp;
		//     }
		//     sumArr[i] = 0;
		// }
        //
		// cout << count << endl;
	}

	return 0;
}

llong maxMinions(const vector<Minion> &m, vector<llong> &dp, int i, int curr_min, llong sum, int count){
	if(i<0){
		double t = ((double)sum)/count;
		if(t <= curr_min)
			return count;
		else
			return 0;
	}

	if(dp[i] != -1)
		return dp[i];

	if(count == 0){
		double t = ((double)(m[i].b))/count;
		if(t<=curr_min)
			dp[i] = 1;
		else
			dp[i] = -1;

		llong x = max(maxMinions(m, dp, i-1, m[i].a, m[i].b, 1), maxMinions(m, dp, i-1, curr_min, 0, 0));
		dp[i] = max(dp[i], x);
	}
	else{

		llong x = max(maxMinions(m, dp, i-1, min(curr_min, m[i].a), sum+m[i].b, count+1), maxMinions(m, dp, i-1, curr_min, sum, count));
		dp[i] = max(x, dp[i]);
	}

	return dp[i];
}
