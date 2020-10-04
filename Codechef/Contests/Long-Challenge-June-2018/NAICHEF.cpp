#include <iostream>
#include <iomanip>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, a, b, x;
	cin >> t;

	while(t--){
		cin >> n >> a >> b;

		int ac = 0;
		int bc = 0;
		int total = 0;
		for(int i=0; i<n; ++i){
			cin >> x;
			if(x==a){
				ac++;
			}
			if(x==b){
				bc++;
			}
			total++;
		}

		float p1 = ((double)ac)/total;
		float p2 = ((double)bc)/total;
		p1 *= p2;

		cout.precision(10);
		cout << std::fixed << p1 << endl;
	}

	return 0;
}
