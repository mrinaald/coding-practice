#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

struct dragon{
	int strength;
	int bonus;
	dragon(int s, int b){
		strength = s;
		bonus = b;
	}
};

bool comparator(const dragon &a, const dragon &b){
	if(a.strength < b.strength)
		return true;
	else
		return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	int s, n, st, bo, i;

	cin >> s >> n;

	vector<dragon> dr;

	for(i=0; i<n; ++i){
		cin >> st >> bo;
		dragon d(st, bo);
		dr.pb(d);
	}

	sort(all(dr), comparator);

	bool flag = true;
	for(i=0; i<n; ++i){
		if(s > dr[i].strength){
			s += dr[i].bonus;
		}
		else{
			flag = false;
			break;
		}
	}

	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
