#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	string a;
	string x = "";

	cin >> n;
	cin >> a;

	int size = a.length();
	for(int i=0; i<size; ++i){
		switch(a[i]){
			case '2' : 	x += "2";
						break;
			case '3' : 	x += "3";
						break;
			case '4' : 	x += "322";
						break;
			case '5' : 	x += "5";
						break;
			case '6' : 	x += "53";
						break;
			case '7' : 	x += "7";
						break;
			case '8' : 	x += "7222";
						break;
			case '9' : 	x += "7332";
						break;
		}
	}
	sort(rall(x));
	cout << x << endl;

	return 0;
}
