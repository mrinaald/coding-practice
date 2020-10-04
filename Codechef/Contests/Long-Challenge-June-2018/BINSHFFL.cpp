#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	llong A, B;

	cin >> t;
	while(t--){
		cin >> A >> B;

		if(A==B){
			cout << 0 << endl;
		}
		else if((B-A)==1){
			cout << 1 << endl;
		}
		else if((B==1) && (A>1)){
			cout << -1 << endl;
		}
		else if((B==0) && (A>0)){
			cout << -1 << endl;
		}
		else{
			bitset<64> b(B-1);
			bitset<64> a(A);

			int noa = a.count();
			int nob = b.count();

			if(nob>=noa){
				cout << nob-noa+1 << endl;
			}
			else{
				cout << 2 << endl;
			}
		}
	}

	return 0;
}
