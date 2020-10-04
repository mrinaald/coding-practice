#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, n, i, j, k;
    vector<int> arr;
    vector<int> counts;

    cin >> t;

    while(t--){
        cin >> n;
        for(i=0; i<n; ++i){
            cin >> j;
            arr.push_back(j);
        }

        sort(arr.begin(), arr.end());

        int offset = -arr[0];
        vector<int> counts(arr[arr.size()-1]+offset, 0);

        for(i=0; i<n; ++i){
            counts[arr[i]+offset]++;
        }
    }

    return 0;
}
