#include <iostream>

#define MOD 1000000007

using namespace std;

long long int fastPow(int x, unsigned long long int n);

int main(){
    unsigned long long int n;
    int w, t;
    cin >> t;

    while(t--){
        cin >> n >> w;
        if((w<-9) || (w>8)){
            cout << 0 << endl;
        }
        else{
            int x = 0;
            long long int ans;
            for(int i=1; i<10; ++i){
                if((w+i)>=0 && (w+i)<10){
                    x++;
                }
            }
            //if(n==2){
                //cout << x << endl;
                //continue;
            //}
            //ans = x;
            n -= 2;
            //for(int i=0; i<n; ++i){
                //ans = ((ans%MOD)*(10%MOD))%MOD;
            //}
            ans = fastPow(10,n);
            ans = ((ans%MOD)*(x%MOD))%MOD;
            cout << ans << endl;
        }
    }
    return 0;
}

long long int fastPow(int x, unsigned long long int n){
    if(n==0)
        return 1;
    if(n==1)
        return x;
    unsigned long long int temp = fastPow(x, n/2)%MOD;
    if(n%2==0){
        return ((temp%MOD)*(temp%MOD))%MOD;
    }
    else{
        temp = ((temp%MOD)*(temp%MOD))%MOD;
        return ((temp%MOD)*(x%MOD))%MOD;
    }
}
