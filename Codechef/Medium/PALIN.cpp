#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, j, k;
	string str;

	cin >> t;
	while(t--){
		cin >> str;
		n = str.length();
		for(i=n-1; i>=0; --i){
			if(str[i]<'9'){
				str[i] += 1;
				break;
			}
			else{
				str[i] = '0';
			}
		}
		if(str[0] == '0'){
			str = '1' + str;
			n += 1;
		}

		i=0;
		j = n-1-i;
		for(; i<=j; i++, j=n-1-i){
			if(str[i] == str[j])
				continue;
			else if(str[i] > str[j]){
				str[j] = str[i];
			}
			else{
				k = j-1;
				while(k>=0){
					str[k] += 1;
					if(str[k] > '9'){
						str[k] = '0';
					}
					else{
						break;
					}
					k--;
				}
				str[j] = str[i];
			}
		}

		cout << str << endl;
	}

	return 0;
}