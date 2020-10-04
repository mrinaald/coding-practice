#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);
	int n;

	cin >> n;

	int k = n/2;

	cout << k << endl;
	for(int i=0; i<(k-1); ++i){
		cout << 2 << ' ';
	}
	cout << ((n%2==0)?2:3) << endl;

	return 0;
}
