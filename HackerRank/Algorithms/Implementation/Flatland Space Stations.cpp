#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    
    sort(c.begin(), c.end());
    
    int i=0;
    int maxdist=0;
    int left=0;
    int right=1;
    
    while(i<n)
    {
        if( (right<m) && (i==c[right]) )
        {
            left++;
            right++;
            i++;
            continue;
        }
        
        if( right < m )
        {
            if( i<=c[left] )
            {
                int dist = c[left]-i;
                if(dist>maxdist)
                    maxdist=dist;
            }
            else
            {
                int dist = (i-c[left])>(c[right]-i)?(c[right]-i):(i-c[left]);
                if( dist>maxdist )
                    maxdist = dist;
            }
        }
        else
        {
            int dist = abs(i - c[left]);
            // abs() used bcoz there may happen that m=1 and c[left]>0
            if( dist>maxdist )
                maxdist = dist;
        }
        i++;
    }
    
    cout << maxdist;
    return 0;
}