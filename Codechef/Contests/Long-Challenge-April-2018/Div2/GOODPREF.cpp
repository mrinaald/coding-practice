#include <iostream>
#include <string>

using namespace std;

int main(){
    int t, n, i, j, k;
    long long int aCount;
    long long int bCount;
    unsigned long long int numPrefixes;
    unsigned long long int len, size;
    long long int extra;
    string s;

    cin >> t;
    while(t--){
        cin >> s >> n;

        len = s.length();

        vector<long long int> countArray(len, 0);

        aCount = bCount = 0;
        for(i=0; i<len, ++i){
            if(s[i]=='a')
                aCount++;
            else if(s[i]=='b')
                bCount++;
            countArray[i] = aCount-bCount;
        }

        extra = (n-1)*countArray[len-1];

        for(i=0; i<len; ++i){
        }

        // if(n > 10000000){
        //     string tempS;
        //     for(i=0; i<6; ++i){
        //         if(s.length() == 16*len)
        //             tempS = s;
        //         s += s;
        //     }
        //     s += tempS;     // 100 times the original length
        // }
        //
        // size = len*n;
        // numPrefixes = 0;
        //
        // for(i=0; i<size; i++){
        //     if(s[i%len] == 'a'){
        //         aCount++;
        //     }
        //     else if(s[i%len] == 'b'){
        //         bCount++;
        //     }
        //
        //     if((aCount-bCount) > 0){
        //         numPrefixes++;
        //     }
        //
        // }
        // cout << numPrefixes << endl;
    }
    return 0;
}
