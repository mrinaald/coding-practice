#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
	std::ios::sync_with_stdio(false);

	int t, n;
	int a, b;
	int i;
	int ans;

	cin >> t;

	while(t--){
		cin >> n;

		vector<pair<int, int> > arr;

		FOR(i, 0, n, 1){
			cin >> a >> b;
			arr.pb(mp(b,a)); 		// (end_point, start_point)
		}

		sort(all(arr));

		i = 0;
		ans = 0;
		while(i < n){
			b = arr[i].first;

			i++;
			while(i < n){
				if((arr[i].second <= b) && (arr[i].first >= b))
					i++;
				else
					break;
			}
			ans++;
		}

		cout << ans << endl;
	}

	return 0;
}
