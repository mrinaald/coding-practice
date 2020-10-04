#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str) {
   stringstream ss(str);
    vector<int> temp;
    int a, n=1;
    char ch=',';
    
    while( n!=0 )
    {
    	ss >> a ;
    	ss.read(&ch, 1);
    	n=ss.gcount();
    	temp.push_back(a);
    }
    return temp;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}