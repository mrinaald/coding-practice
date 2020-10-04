#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define MAX_N 5000
#define MOD 1000000007
#define MOD1 1000000006

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;

llong **choose;

void compute_choose();
llong nChoosek(int n, int k);
llong func(vector<int> &arr, int k);
llong raisep(int a, int p);

int main(){
	std::ios::sync_with_stdio(false);

	int n, t, k;
	int i;

	cin >> t;

	choose = new llong*[MAX_N+1];
	for(i=0; i<=MAX_N; ++i){
		choose[i] = new llong[MAX_N+1];
	}

	compute_choose();

	while(t--){
		cin >> n >> k;

		vector<int> arr(n, 0);

		for(i=0; i<n; ++i){
			cin >> arr[i];
		}

		sort(all(arr));

		cout << func(arr, k) << endl;
	}

	return 0;
}

void compute_choose(){
	int n, k;

	choose[0][0] = 1;

	for(n=1; n<=MAX_N; ++n){
		for(k=0; k<=n; ++k){
			if((k==0) || (k==n)){
				choose[n][k] = 1;
			}
			else{
				choose[n][k] = ((choose[n-1][k-1]%MOD1) + (choose[n-1][k]%MOD1))%MOD1;
			}
		}
	}

}

llong nChoosek(int n, int k){
	if(k > n || n < 0)
		return 0;

	return choose[n][k];
}

llong raisep(int a, int p){
	if(p==0)
		return 1;
	if(p==1)
		return (llong)a;

	llong temp = raisep(a, p/2);

	temp = ((temp%MOD) * (temp%MOD))%MOD;
	if(p%2 == 0){
		return temp;
	}
	else{
		return ((temp%MOD) * (a%MOD))%MOD;
	}
}

llong func(vector<int> &arr, int k){
	int i;
	llong ans = 1;
	llong c1, c2, c3;

	int n = arr.size();

	for(i=0; i<n; ++i){
		c1 = nChoosek(n-1, k-1); 		// numerator
		c2 = nChoosek(n-1-i, k-1); 		// denominator
		c3 = nChoosek(i, k-1); 			// denominator

		c1 = (c1 - c2 - c3)%MOD1;
		if(c1 < 0)
			c1 += MOD1;

		ans = ((ans%MOD) * (raisep(arr[i], c1)%MOD))%MOD;
	}

	return ans;
}
