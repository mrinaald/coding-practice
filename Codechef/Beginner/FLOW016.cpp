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

llong gcd(llong a, llong b){
	if(b==1)
		return 1;
	if((b==0) || (b==a))
		return a;

	if(a < b)
		return gcd(b, a);
	else
		return gcd(b, a%b);
}

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	llong a, b, g, temp;

	cin >> t;

	while(t--){
		cin >> a >> b;

		g = gcd(a, b);

		temp = a*b;

		cout << g << ' ' << (temp/g) << endl;
	}

	return 0;
}
