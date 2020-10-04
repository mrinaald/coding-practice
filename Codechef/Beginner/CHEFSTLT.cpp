#include <iostream>
#include <string>

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
	string s1, s2;
	int i, j;
	int min_diff;
	int q_count;

	cin >> t;

	while(t--){
		cin >> s1;
		cin >> s2;

		min_diff = q_count = 0;

		n = s1.length();

		for(i=0; i<n; ++i){
			if((s1[i]=='?') || (s2[i]=='?')){
				q_count++;
			}
			else if(s1[i] != s2[i]){
				min_diff++;
			}
		}

		cout << min_diff << ' ' << min_diff + q_count << endl;
	}

	return 0;
}
