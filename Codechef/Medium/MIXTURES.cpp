#include <iostream>
#include <vector>

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

vector<int> arr(100);
vector<llong> sumarr(100);
vector<vector<int> > dparr(100, vector<int>(100,-1));
int n;

llong func(int l, int r);
llong sum(int l, int r);

int main(){
	std::ios::sync_with_stdio(false);

	int i, j;

	while(cin >> n){
		cin >> arr[0];
		sumarr[0] = arr[0];

		FOR(i, 1, n, 1){
			cin >> arr[i];
			sumarr[i] = sumarr[i-1] + arr[i];
		}

		FOR(i, 0, n, 1){
			FOR(j, 0, n, 1){
				dparr[i][j] = -1;
			}
		}

		cout << func(0, n-1) << endl;
	}

	return 0;
}

llong func(int l, int r){
	if(l >= r)
		return 0;

	if(dparr[l][r] != -1)
		return dparr[l][r];

	int i;
	llong lsum, rsum, min_smoke, smoke;
	llong left_smoke, right_smoke;
	min_smoke = 1000000000000;

	FOR(i, l, r, 1){
		lsum = sum(l, i);
		rsum = sum(i+1, r);

		smoke = (lsum*rsum) + func(l, i) + func(i+1, r);
		if(smoke < min_smoke)
			min_smoke = smoke;
	}

	dparr[l][r] = min_smoke;

	return min_smoke;
}

llong sum(int l, int r){
	// int i;
	// llong ans = 0;
    //
	// FORE(i, l, r, 1){
	//     ans += arr[i];
	// }
    //
	// return ans%100;
	if(l==0){
		return (sumarr[r])%100;
	}
	else{
		return (sumarr[r] - sumarr[l-1])%100;
	}
}
