#include <iostream>
#include <cmath>

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

	int t, n;
	int i, j, temp;
	int min_diff;

	cin >> t;

	while(t--){
		cin >> n;

		min_diff = 2000000000;

		temp = sqrt(n);

		for(i=temp; i>=1; --i){
			if(n%i != 0)
				continue;

			j = (n/i) - i;
			if(j < min_diff)
				min_diff = j;
		}

		cout << min_diff << endl;
	}

	return 0;
}
