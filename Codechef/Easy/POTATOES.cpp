#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

vector<bool> primes(40000, true);

void compute_soe();

int main(){
	std::ios::sync_with_stdio(false);

	int t, x, y;
	int i, sum;

	cin >> t;

	compute_soe();

	while(t--){
		cin >> x >> y;

		for(i=1;;++i){
			sum = x+y+i;
			if(primes[sum] == true)
				break;
		}

		cout << i << endl;
	}

	return 0;
}

void compute_soe(){
	int i, j;

	for(i=2; i<40000; ++i){
		if(primes[i] == false)
			continue;
		for(j=2*i; j<40000; j+=i)
			primes[j] = false;
	}
}
