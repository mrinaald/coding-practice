#include <iostream>
#include <string>

using namespace std;

bool isHello(string str);

int main(){
	string s;

	cin >> s;

    if(isHello(s)){
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

	return 0;
}

bool isHello(string str){
    int n = str.length();
    int count = 0;
    for(int i=0; i<n; ++i){
        if(count==0){
            if(str[i]=='h')
                count++;
            continue;
        }
        if(count==1){
            if(str[i]=='e')
                count++;
            continue;
        }
        if(count==2){
            if(str[i]=='l')
                count++;
            continue;
        }
        if(count==3){
            if(str[i]=='l')
                count++;
            continue;
        }
        if(count==4){
            if(str[i]=='o')
                count++;
            continue;
        }
    }
    return count==5;
}
