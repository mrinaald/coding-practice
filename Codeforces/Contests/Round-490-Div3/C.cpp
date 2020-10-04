#include <iostream>
#include <vector>
#include <string>

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

	int n, k, i, j;

	string ins;
	cin >> n >> k;
	cin >> ins;

	vector<int> buck(26, 0);

	for(i=0; i<n; ++i){
		buck[ins[i]-'a'] += 1;
	}

	for(i=0; i<26; ++i){
		if( k > buck[i]){
			k -= buck[i];
		}
		else{
			buck[i] = k;
			k = 0;
		}
	}

	int ch;
	for(i=0; i<n; ++i){
		ch = ins[i] - 'a';
		if(buck[ch] != 0){
			buck[ch] -= 1;
			continue;
		}
		cout << ins[i];
	}
	cout << endl;

	return 0;
}
