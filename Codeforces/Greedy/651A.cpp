#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int a1, a2;
	int mins = 0;
	cin >> a1 >> a2;

	while(1){
		if((a1==0) || (a2==0))
			break;
		if((a1==1) && (a2==1))
			break;
		if(a1<a2){
			a1++;
			a2 -= 2;
			mins++;
		}
		else{
			a2++;
			a1 -= 2;
			mins++;
		}
	}
	cout << mins << endl;

	return 0;
}
