#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

struct ST{
	int len;
	string s;

	ST(string st){
		len = st.length();
		s = st;
	}
};

bool comparator(const ST& l, const ST& r){
	return l.len < r.len;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, i, x;
	string st;

	cin >> n;
	vector<ST> arr;

	for(i=0; i<n; ++i){
		cin >> st;
		ST s(st);
		arr.pb(s);
	}

	sort(all(arr), comparator);

	bool possible = true;
	for(i=1; i<n; ++i){
		size_t f = arr[i].s.find(arr[i-1].s);
		if(f == string::npos){
			possible = false;
			break;
		}
	}

	if(possible){
		cout << "YES" << endl;
		for(i=0; i<n; ++i){
			cout << arr[i].s << endl;
		}
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}
