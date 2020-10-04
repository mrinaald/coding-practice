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

int *arr;
bool *flag;
int n;

int func(int bitnum);

int main(){
	std::ios::sync_with_stdio(false);

	int i;

	cin >> n;

	arr = new int[n];
	flag = new bool[n];

	FOR(i, 0, n, 1){
		cin >> arr[i];
		flag[i] = true;
		// cout << "*** " << arr[i] << ' ' << flag[i] << endl;
	}

	cout << func(29) << endl;

	delete arr;
	delete flag;

	return 0;
}

int func(int bitnum){
	if(bitnum == -1)
		return 0;

	int i;
	int ans = 0;
	int bitnumcount = 0;
	FOR(i, 0, n, 1){
		if(flag[i] == true){
			if(arr[i] & (1<<bitnum))
				bitnumcount++;
		}
	}

	if(bitnumcount >= 2){
		ans = (1<<bitnum);
		// cout << "***** " << bitnum << ' ' << ans << endl;
		FOR(i, 0, n, 1){
			if((arr[i] & (1<<bitnum)) == 0){
				flag[i] = false;
			}
		}
	}

	return ans + func(bitnum-1);
}
