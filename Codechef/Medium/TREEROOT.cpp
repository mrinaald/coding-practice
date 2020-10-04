#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, i;
	int x, y;
	llong ans;

	cin >> t;

	while(t--){
		cin >> n;

		ans = 0;
		for(i=0; i<n; ++i){
			cin >> x >> y;
			ans += x-y;
		}

		cout << ans << endl;
	}

	return 0;
}
