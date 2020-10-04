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

	int n, i, j, k;
	llong count = 0;
	llong st = 0;
	string temp;

	cin >> n;

	vector<string> arr(n, "");
	vector<int> stptr(n, 0);
	vector<bool> possibility(n, true);
	
	for(i=0; i<n; ++i){
		cin >> arr[i];
		k = arr[i].length();
		for(j=0; j<k; ++j){
			if(arr[i][j] == ')')
				stptr[i] -= 1;
			if(arr[i][j] == '(')
				stptr[i] += 1;
			if(stptr[i] < 0)
				possibility[i] = false;
		}
	}

	// for(i=0; i<n; ++i){
	//     for(j=0; j<n; ++j){
	//         // if((stptr[i]>=0) && (possibility[i])){
	//         if(possibility[i]){
	//             if((stptr[i]+stptr[j])==0)
	//                 count++;
	//         }
	//         // if(i==j){
	//         //     if((stptr[i]+stptr[i])==0)
	//         //         count++;
	//         // }
	//         // else{
	//         //     if(stptr[i]>=0){
	//         //         if((stptr[i]+stptr[j])==0)
	//         //             count++;
	//         //     }
	//         //     if(stptr[j]>=0){
	//         //         if((stptr[i]+stptr[j])==0)
	//         //             count++;
	//         //     }
	//         // }
	//     }
	// }

	for(i=0; i<n; ++i){
		for(j=i; j<n; ++j){
			st = 0;
			temp = arr[i] + arr[j];
			for(k=0 ; k<temp.length(); ++k){
				if(temp[k] == '(')
					st++;
				if(temp[k] == ')')
					st--;
				if(st < 0)
					break;
			}
			if(st == 0)
				count ++;

			if(i==j)
				continue;
			st = 0;
			temp = arr[j] + arr[i];
			for(k=0 ; k<temp.length(); ++k){
				if(temp[k] == '(')
					st++;
				if(temp[k] == ')')
					st--;
				if(st < 0)
					break;
			}
			if(st == 0)
				count ++;
		}
	}

	cout << count << endl;

	return 0;
}
