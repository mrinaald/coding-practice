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

int sum(int n){
	int x;
	if(n%2 == 0){
		x = n/2;
		x *= (n+1);
	}
	else{
		x = (n+1)/2;
		x *= n;
	}
	return x;
}

int main(){
	std::ios::sync_with_stdio(false);

	int t, d, n, i;
	int s;

	cin >> t;

	while(t--){
		cin >> d >> n;

		s = n;
		for(i=0; i<d; ++i){
			s = sum(s);
		}

		cout << s << endl;
	}

	return 0;
}
