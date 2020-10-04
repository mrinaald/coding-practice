#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, i;

	cin >> t;

	while(t--){
		string str;
		cin >> str;

		n = str.length();

		int countLT = 0;
		int countGT = 0;
		int maxCountLT = 0;
		int maxCountGT = 0;

		for(i=0; i<n; ++i){
			if(str[i] == '<'){
				if(countGT != 0){
					if(countGT > maxCountGT)
						maxCountGT = countGT;
					countGT = 0;
				}
				countLT++;
			}
			else if(str[i] == '>'){
				if(countLT != 0){
					if(countLT > maxCountLT)
						maxCountLT = countLT;
					countLT = 0;
				}
				countGT++;
			}
		}

		if(countLT != 0){
			if(countLT > maxCountLT)
				maxCountLT = countLT;
		}

		if(countGT != 0){
			if(countGT > maxCountGT)
				maxCountGT = countGT;
		}

		cout << max(maxCountLT, maxCountGT) + 1 << endl;
	}

	return 0;
}
