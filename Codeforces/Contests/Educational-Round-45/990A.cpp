#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	long long int n, m;
	int a, b;

	cin >> n >> m >> a >> b;

	if(n%m==0)
		cout << 0 << endl;
	else{
		long long int neg = n%m;
		long long int pos = m-neg;
		cout << min(neg*b, pos*a) << endl;
	}

	return 0;
}
