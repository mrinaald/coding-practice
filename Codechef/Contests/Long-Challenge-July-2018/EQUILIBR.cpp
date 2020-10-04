#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define MOD 1000000007

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

llong power(llong a, llong p);

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	llong num = n;
	llong den = power(2, n-1);
	num = ((den%MOD) - (num%MOD))%MOD;

	// cout << num << ' ' << den << endl;
	den = power(den, MOD-2);

	llong ans = ((num%MOD) * (den%MOD))%MOD;

	cout << ans << endl;

	return 0;
}

llong power(llong a, llong p){
	if(p == 0)
		return 1;
	if(p == 1)
		return a;

	llong temp = power(a, p/2)%MOD;
	temp = ((temp%MOD) * (temp%MOD))%MOD;

	if(p%2 == 0){
		return temp;
	}
	else{
		temp = ((temp%MOD) * (a%MOD))%MOD;
		return temp;
	}
}
