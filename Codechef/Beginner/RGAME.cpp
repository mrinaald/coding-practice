#include <iostream>
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

vector<llong> power_2(100001, -1);

llong power(int n);

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, a;
	int i, j;
	llong sol, temp;

	cin >> t;

	while(t--){
		cin >> n;

		vector<int> nums(n+1);
		llong first_half;
		vector<llong> second_half(n+1);

		for(i=0; i<=n; ++i){
			cin >> nums[i];
			second_half[i] = ((nums[i]%MOD) * (power(n-i)%MOD))%MOD;
		}

		for(i=n-1; i>=0; --i){
			second_half[i] = ((second_half[i]%MOD) + (second_half[i+1]%MOD))%MOD;
		}

		sol = 0;

		for(i=0; i<n; ++i){
			first_half = ((nums[i]%MOD) * (power(i-1)%MOD))%MOD;
			first_half = ((first_half%MOD) * (second_half[i+1]%MOD))%MOD;

			sol = ((sol%MOD) + (first_half%MOD))%MOD;
		}

		sol = ((sol%MOD) * (2))%MOD;

		cout << sol << endl;
	}

	return 0;
}

llong power(int n){
	// for n == -1, we require 1 as answer
	if(n <= 0)
		return 1;
	if(n == 1)
		return 2;

	if(power_2[n] != -1)
		return power_2[n];

	llong temp = power(n/2);

	temp = ((temp%MOD) * (temp%MOD))%MOD;
	if(n%2 == 0){
		power_2[n] = temp;
	}
	else{
		power_2[n] = ((temp%MOD) * (2))%MOD;
	}

	return power_2[n];
}
