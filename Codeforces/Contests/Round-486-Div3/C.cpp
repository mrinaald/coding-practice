#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

struct A{
	int sno;
	int id;

	void init(int s, int i){
		sno = s;
		id = i;
	}
}ans1, ans2;

int main(){
	std::ios::sync_with_stdio(false);

	int k, n, i, x;
	bool flag = false;
	map<long long int, A> m;

	cin >> k;
	int K = k;
	while(k--){
		cin >> n;

		vector<long long int> arr;
		long long int sum = 0;
		for(i=0; i<n; ++i){
			cin >> x;
			sum += x;
			arr.pb(x);
		}

		if(flag)
			continue;

		long long int s;
		for(i=0; i<n; ++i){
			s = sum - arr[i];
			if(m.find(s) != m.end()){
				if(m[s].sno != k){
					ans1.init(m[s].sno, m[s].id);
					ans2.init(k, i+1);
					flag = true;
				}
			}
			else{
				A a;
				a.init(k, i+1);
				m.insert(mp(s, a));
			}
		}
	}

	if(flag){
		cout << "YES" << endl;
		cout << K - ans1.sno << ' ' << ans1.id << endl;
		cout << K - ans2.sno << ' ' << ans2.id << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}
