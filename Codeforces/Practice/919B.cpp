#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;

llong perfectNum(int k);
bool check(llong x);

int main(){
	std::ios::sync_with_stdio(false);

	int k;
	cin >> k;

	cout << perfectNum(k) << endl;

	return 0;
}

llong perfectNum(int k){
	int m = 2;
	llong x;
	for(int i=0; i<k; ){
		x = 9*m + 1;
		if(check(x))
			i++;
		m++;
	}
	return x;
}

bool check(llong x){
	int sum = 0;
	while(x>0){
		sum += x%10;
		x /= 10;
	}

	return sum==10;
}
