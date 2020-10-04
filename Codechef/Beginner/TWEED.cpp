#include <iostream>
#include <vector>
#include <string>

using namespace std;

string winner(vector<int> &A, bool id);

vector<string> names(2);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, temp;
	string str;

	names[0] = "Dee";
	names[1] = "Dum";

	cin >> t;
	while(t--){
		cin >> n >> str;

		vector<int> A;
		for(i=0; i<n; ++i){
			cin >> temp;
			A.push_back(temp);
		}

		// cout << n << '*' << str << endl;
		// for(i=0; i<n; ++i)
		// 	cout << A[i] << ' ';
		// cout << endl;
		cout << winner(A, str=="Dum") << endl;
	}

	return 0;
}

string winner(vector<int> &A, bool id){
	int n = A.size();
	
	if(id)		// Dum's turn
	{
		int odd, evn;
		int i, ind;
		evn = odd = -1;

		for(i=0; i<n; ++i){
			if(A[i] == 0)
				continue;
			if(A[i]%2 == 0){
				evn = A[i];
				ind = i;
				break;
			}
			else if(A[i] > odd){
				odd = A[i];
				ind = i;
			}
		}

		if(evn != -1){
			A[ind] = 1;
			return winner(A, !id);
		}
		else if(odd != -1){
			A[ind] = 0;
			return winner(A, !id);
		}
		else
			return names[!id];
	}
	else{				// Dee's Turn
		int odd, evn;
		int i, ind;
		evn = odd = -1;

		for(i=0; i<n; ++i){
			if(A[i] <= 1)
				continue;
			if(A[i]%2 == 0){
				evn = A[i];
				ind = i;
				break;
			}
			else if (A[i] > odd){
				odd = A[i];
				ind = i;
			}
		}

		if(evn != -1){
			A[ind] = 0;
			return winner(A, !id);
		}
		else if(odd != -1){
			A[ind] = 1;
			return winner(A, !id);
		}
		else
			return names[!id];		
	}

	// return names[id];
}