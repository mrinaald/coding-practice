#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, k, i, temp;

	cin >> n >> k;

	vector<int> person;

	for(i=0; i<n; ++i){
		cin >> temp;
		person.pb(temp);
	}

	sort(all(person));

	temp = 5-k;

	int numTeams = 0;
	for(i=2; i<n; i+=3){
		if(person[i]<=temp)
			numTeams++;
	}

	cout << numTeams << endl;

	return 0;
}
