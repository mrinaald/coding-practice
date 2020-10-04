#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

struct examDate{
	long int actual;
	long int before;

	examDate(long int a, long int b){
		actual = a;
		before = b;
	}
};

bool comparator(const examDate &a, const examDate &b){
	if(a.actual < b.actual)
		return true;
	else if(a.actual == b.actual){
		if(a.before < b.before)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, i;
	long int a, b;
	vector<examDate> exams;

	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a >> b;
		examDate e(a,b);
		exams.pb(e);
	}

	// cout << "****" << endl;
	sort(all(exams), comparator);
	int lastDate = exams[0].before;
	for(i=1; i<n; ++i){
		// cout << exams[i].actual << ' ' << exams[i].before << endl;
		if(exams[i].before >= lastDate){
			lastDate = exams[i].before;
		}
		else{
			lastDate = exams[i].actual;
		}
	}
	cout << lastDate << endl;

	return 0;
}
