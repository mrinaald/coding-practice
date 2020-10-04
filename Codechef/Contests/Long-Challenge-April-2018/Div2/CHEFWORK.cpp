#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int i,j,k;
    vector<int> coins;
    vector<int> authCoins;
    vector<int> transCoins;
    vector<int> authTransCoins;
    int n;

    cin >> n;
    for(i=0; i<n; ++i){
        cin >> k;
        coins.push_back(k);
    }

    int minAuth = 1000000;
    int minTrans = 1000000;
    int minAuthTrans = 1000000;
    for(i=0; i<n; ++i){
        cin >> k;
        switch(k){
            case 1: transCoins.push_back(coins[i]);
                    if(coins[i] < minTrans){
                        minTrans = coins[i];
                    }
                    break;
            case 2: authCoins.push_back(coins[i]);
                    if(coins[i] < minAuth){
                        minAuth = coins[i];
                    }
                    break;
            case 3: authTransCoins.push_back(coins[i]);
                    if(coins[i] < minAuthTrans){
                        minAuthTrans = coins[i];
                    }
                    break;
        }
    }

    if(minAuth+minTrans < minAuthTrans)
        cout << minAuth + minTrans << endl;
    else
        cout << minAuthTrans << endl;
    return 0;
}
