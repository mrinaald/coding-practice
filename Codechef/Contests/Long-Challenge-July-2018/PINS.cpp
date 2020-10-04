#include <iostream>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;

int main(){
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, x;
	string a;

	cin >> t;

	while(t--){
		cin >> n;

		x = n/2;

		a = "1";
		for(i=1; i<=x; ++i){
			a += "0";
		}

		cout << 1 << ' ' << a << endl;
	}

	return 0;
}
