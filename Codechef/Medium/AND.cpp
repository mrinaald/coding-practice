#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i, l, h, x) for(i=l; i<h; i+=x)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	int i, t, j, x;
	llong ans = 0;
	llong s;
	vector<int> count(32, 0);

	cin >> n;

	FOR(i, 0, n, 1){
		cin >> x;

		j = 0;
		while(x>0){
			t = x%2;
			count[j] += t;
			j++;
			x = x>>1;
		}
	}

	FOR(i, 0, 32, 1){
		if(count[i] < 2)
			continue;

		if(count[i]%2 == 0){
			s = count[i]/2;
			s = s*(count[i]-1);
		}
		else{
			s = (count[i]-1)/2;
			s = s*count[i];
		}

		s = s*(1<<i);

		ans += s;
	}

	cout << ans << endl;

	return 0;
}
