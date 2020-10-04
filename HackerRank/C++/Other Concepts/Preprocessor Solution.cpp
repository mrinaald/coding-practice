// Enter your code here
#include <climits>
#define toStr(x) "Result ="
#define io(v) cin>>v
#define INF INT_MAX
#define foreach(v, i) for(int i=0; i<v.size(); ++i)
#define FUNCTION(func, x) void func(int &a, int b){ a=(a x b)?a:b; }

// Don't edit the code below
#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}