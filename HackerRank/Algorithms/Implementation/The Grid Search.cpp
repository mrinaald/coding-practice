#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool findPattern(vector<string> G, int R, int C, vector<string> P, int r, int c);
bool checkPattern(vector<string> G, int R, int C, vector<string> P, int r, int c, int i, int j);
int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        
        if(findPattern(G, R, C, P, r, c))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

bool findPattern(vector<string> G, int R, int C, vector<string> P, int r, int c)
{
    for(int i=0; i<R; ++i)
    {
        for(int j=0; j<C; ++j)
        {
            if(G[i][j]==P[0][0])
                if(checkPattern(G, R, C, P, r, c, i, j))
                    return true;
        }
    }
    return false;
}

bool checkPattern(vector<string> G, int R, int C, vector<string> P, int r, int c, int i, int j)
{
    int orig_i=i;
    int orig_j=j;
    int x, y;
    for(x=0; (x<r)&&(i<R); ++x, ++i)
    {
        for(y=0, j=orig_j; (y<c)&&(j<C); ++y, ++j)
            if( G[i][j] != P[x][y] )
                return false;
        
        if( (y!=c)&&(j==C) )
            return false;
    }
    if( (x!=r)&&(i==R) )
        return false;
    
    return true;
}