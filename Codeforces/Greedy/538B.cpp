#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int maxDigit(string str){
	int md = 0;
	int n = str.length();
	int x;

	for(int i=0; i<n; ++i){
		x = str[i] - '0';
		if(x > md)
			md = x;
	}
	return md;
}

int main(){
	std::ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int n = str.length();
	int num, x, i, t;
	vector<string> ans;

	int d = maxDigit(str);
	ans.assign(d, "");

	for(i=0; i<n; ++i){
		x = str[i] - '0';
		for(t=0; t<x; ++t){
			ans[t] += "1";
		}
		for(; t<d; ++t){
			ans[t] += "0";
		}
	}

	cout << d << endl;
	for(i=d-1; i>=0; --i){
		cout << stoi(ans[i]) << ' ';
	}
	cout << endl;

	return 0;
}
