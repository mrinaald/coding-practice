#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define MAX_N 100000

int f(int l, int r);
void compute(string s);
vector<long int> sol;
string str;

int main(){
	// std::ios_base::sync_with_stdio(false);

	int n, m, l, r;

	cin >> str;
	n = str.length();

	sol.assign(n, 0);
	compute(str);

	cin >> m;
	while(m--){
		scanf("%d", &l);
		scanf("%d", &r);
		// cout << l << ' ' << r << endl;
		cout << f(l-1, r-1) << endl;
	}

	return 0;
}

int f(int l, int r){
	return sol[r] - sol[l];
}

void compute(string s){
	int n = s.length();
	int i;
	for(i=1; i<n; ++i){
		sol[i] = sol[i-1] + int(s[i]==s[i-1]);
	}
}
