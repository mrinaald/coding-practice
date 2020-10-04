#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, m;
	int teams = 0;

	cin >> n >> m;

	while((n+m>2)&&(n>0)&&(m>0)){
		if(n>m){
			n -= 2;
			m -= 1;
			teams++;
		}
		else{
			m -= 2;
			n -= 1;
			teams++;
		}
	}

	cout << teams << endl;

	return 0;
}
