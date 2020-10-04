#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef unsigned long long int ull;

vector<ull> fib(100001);

void computeFibonacci(){
	fib[0] = 0;
	fib[1] = 1;
	for(int i=2; i<fib.size(); ++i){
		fib[i] = ((fib[i-1]%MOD)+(fib[i-2])%MOD)%MOD;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, m, temp, i, j, k;
	ull sum=0;
	ull resultA, resultB;
	ull result;

	cin >> t;
	computeFibonacci();

	while(t--){
		cin >> m >> n;

		sum = 0;
		vector<int> seqA, seqB;
		for(i=0; i<m; ++i){
			cin >> temp;
			seqA.push_back(temp);
		}
		for(i=0; i<m; ++i){
			cin >> temp;
			seqB.push_back(temp);
		}

		// for(i=0; i<m; ++i){
		//     for(j=0; j<m; ++j){
		//         if(n==1){
		//             result = seqA[i];
		//         }
		//         else if(n==2){
		//             result = seqB[j];
		//         }
		//         else{
		//             resultA = ((fib[n-2]%MOD)*(seqA[i]%MOD))%MOD;
		//             resultB = ((fib[n-1]%MOD)*(seqB[j]%MOD))%MOD;
		//             result = ((resultA%MOD)+(resultB%MOD))%MOD;
		//         }
        //
		//         sum = ((sum%MOD)+(result%MOD))%MOD;
		//     }
		// }

		for(i=0; i<m; ++i){
			if(n==1){
				result = ((m%MOD)*(seqA[i]%MOD))%MOD;
			}
			else if(n==2){
				result = ((m%MOD)*(seqB[i]%MOD))%MOD;
			}
			else{
				resultA = ((fib[n-2]%MOD)*(seqA[i]%MOD))%MOD;
				resultA = ((m%MOD)*(resultA%MOD))%MOD;

				resultB = ((fib[n-1]%MOD)*(seqB[i]%MOD))%MOD;
				resultB = ((m%MOD)*(resultB%MOD))%MOD;

				result = ((resultA%MOD)+(resultB%MOD))%MOD;
			}

			sum = ((sum%MOD) + (result%MOD))%MOD;
		}

		cout << (sum%MOD) << endl;
	}

	return 0;
}
