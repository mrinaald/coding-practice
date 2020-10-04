#include <iostream>
#include <string>
#include <vector>

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

	int n;
	int i, j;
	string ins;
	string ls = "";
	string rs = "";

	cin >> n;
	cin >> ins;

	vector<int> divs;
	divs.pb(0);
	for(i=2; i<=(n/2); ++i){
		if(n%i == 0)
			divs.pb(i-1);
	}
	divs.pb(n-1);

	bool left = false;
	for(i=divs.size()-1; i>0; --i){
		left = !left;
		for(j=divs[i]; j>divs[i-1]; --j){
			if(left){
				ls += ins[j];
			}
			else{
				rs = ins[j] + rs;
			}
		}
	}
	left = !left;
	if(left){
		ls += ins[0];
	}
	else{
		rs  = ins[0] + rs;
	}

	cout << ls << rs << endl;

	return 0;
}
