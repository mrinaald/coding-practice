/*********************************************************************
*** Implemented Doubly Linked List using two 3 arrays to make 
*** deletion of internal elements efficient
*********************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int n, k;
	string str;
	int i, j;
	short prevTweet = -1;
	// bool allClosed = false;
	int count = 0;
	
	cin >> n >> k;
	vector<bool> openTweet(n,false);
	vector<short> backRef(n, -1);
	vector<short> nextRef(n, -1);

	while(k--){
		cin >> str;
		if(str == "CLICK"){
			cin >> i;

			i -= 1;			// indices are starting from 0
			if(openTweet[i] == false){
				count++;
				openTweet[i] = true;

				backRef[i] = prevTweet;
				if(prevTweet != -1)
					nextRef[prevTweet] = i;
				prevTweet = i;
			}
			else{
				count--;
				openTweet[i] = false;
				if(backRef[i] != -1){
					nextRef[backRef[i]] = nextRef[i];
				}
				if(nextRef[i] != -1){
					backRef[nextRef[i]] = backRef[i];
				}
				if(prevTweet == i){
					prevTweet = backRef[i];
				}
				backRef[i] = -1;
				nextRef[i] = -1;
			}
		}
		else{
			if(count > 0){
				count = 0;
				while(prevTweet != -1){
					i = prevTweet;
					if(backRef[i] != -1){
						nextRef[backRef[i]] = -1;
					}
					prevTweet = backRef[i];
					openTweet[i] = false;
					backRef[i] = -1;
				}

			}
		}

		cout << count << endl;
	}

	return 0;
}