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

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, k, i;
	int max_x;
	int temp;

	cin >> t;

	while(t--){
		cin >> n >> k;

		max_x = -1;
		for(i=2; i<=k; ++i){
			temp = n%i;
			if(temp > max_x)
				max_x = temp;
		}

		cout << max_x << endl;
	}

	return 0;
}
