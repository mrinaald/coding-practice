#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

void dp(int n, int i, int currP);

long long int total = 0;
long long int pCount = 0;
string s1, s2;
int p = 0;
// vector<bool> present(21, false);

int main(){
	std::ios::sync_with_stdio(false);

	cin >> s1;
	cin >> s2;

	int n = s1.length();
	int i;
	for(i=0; i<n; ++i){
		if(s1[i] == '+')
			p++;
		else if(s1[i] == '-')
			p--;
	}

	dp(n, 0, 0);
	printf("%.9lf\n", ((double)pCount)/total);
	// cout.precision(12);
	// cout << std::fixed << ((double)pCount)/total << endl;

	return 0;
}

void dp(int n, int i, int currP){
	if(i>=n){
		if(currP == p)
			pCount++;
		total++;
		return;
	}

	if(s2[i] =='+'){
		dp(n, i+1, currP+1);
	}
	if(s2[i] =='-'){
		dp(n, i+1, currP-1);
	}
	if(s2[i] == '?'){
		dp(n, i+1, currP+1);
		dp(n, i+1, currP-1);
	}
}
