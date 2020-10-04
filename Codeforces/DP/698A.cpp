#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int func(int id, int nd);
vector<int> arr;
vector<vector<int> > dp;
int n;

int main(){
	std::ios::sync_with_stdio(false);

	cin >> n;

	arr.assign(n, 0);
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}

	dp.assign(n, vector<int>(3,-1));
	cout << func(n-1, 0) << endl;

	return 0;
}

int func(int id, int nd){
	if(id<0){
		return 0;
	}
	if(dp[id][nd] != -1){
		return dp[id][nd];
	}

	 switch(arr[id]){
		 case 0 : dp[id][nd] = func(id-1, 0) + 1;
				  break;
		 case 1 : if(nd==1){
					  dp[id][nd] = func(id-1, 0) + 1;
				  }
				  else{
					  dp[id][nd] = min(func(id-1, 0)+1, func(id-1, 1));
				  }
				  break;
		 case 2 : if(nd==2){
					  dp[id][nd] = func(id-1, 0) + 1;
				  }
				  else{
					  dp[id][nd] = min(func(id-1, 0)+1, func(id-1, 2));
				  }
				  break;
		 case 3 : if(nd==1){
					  dp[id][nd] = min(func(id-1, 0)+1, func(id-1, 2));
				  }
				  else if(nd==2){
					  dp[id][nd] = min(func(id-1, 0)+1, func(id-1, 1));
				  }
				  else{
					  dp[id][nd] = min(func(id-1, 0)+1, min(func(id-1, 1), func(id-1, 2)));
				  }
				  break;
	 }

	return dp[id][nd];
}
