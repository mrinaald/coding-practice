/*************************************************************************
next_permutation() function, available in <algorithmm>, can also be used
*************************************************************************/
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    string str;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> str;
        
        int len = str.length();
        int i=len-1;
        while(i>=1)
        {
            if(str[i-1] < str[i])
                break;
            i--;
        }
        
        if(i)
        {
            //sorting from 'i-th' index till end
            string::iterator it = str.begin();
            advance(it, i);
            sort(it, str.end());
            
            i--;    // making i = index to be replaced.
            // finding the smallest char greater than 'i-th' char
            for(int j=i+1; j<len; ++j)
            {
                if(str[j] > str[i])
                {
                    char temp = str[j];
                    str[j] = str[i];
                    str[i] = temp;
                    break;
                }
            }
            cout << str << '\n';
        }
        else
            cout << "no answer\n";
    }
    return 0;
}