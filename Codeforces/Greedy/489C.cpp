#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int m, s, i, temp;
	bool flag = true;

	cin >> m >> s;

	if((m==1) && (s==0)){
		cout << "0 0" << endl;
		return 0;
	}

	vector<int> num(m, 0);
	num[m-1] = 1;
	s -= 1;

	if(s<0){
		flag = false;
	}

	i=0;
	while((s>0) && (i<m)){
		if(s>9){
			num[i] += 9;
			s -= 9;
			i++;
		}
		else{
			num[i] += s;
			s = 0;
			i++;
			break;
		}
	}
	int len = i;
	if((s!= 0) || (num[m-1] > 9))
		flag = false;

	if(flag==false){
		cout << -1 << ' ' << -1 << endl;
	}
	else{
		// printing min number
		for(i=m-1; i>=0; --i){
			cout << num[i];
		}
		cout << ' ';

		// printing max number
		for(i=m-1; i>=1; --i){
			if(num[i]+num[i-1] <=9){
				num[i-1] += num[i];
				num[i] = 0;
			}
		}
		for(i=0; i<m; ++i){
			cout << num[i];
		}
		cout << endl;
	}

	return 0;
}
