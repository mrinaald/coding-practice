#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define CHARS 26

struct TrieNode{
	int firstApp;
	int endId;
	bool isEnd;
	char name;

	vector<TrieNode*> children;

	TrieNode(char ch, int fa){
		firstApp = fa;
		endId = -1;
		isEnd = false;
		children.assign(CHARS, NULL);
		name = ch;
	}

	void makeEnd(int id){
		isEnd = true;
		// We should keep the minimum index
		if(endId == -1)
			endId = id;
	}
};

class Trie{
	vector<TrieNode*> headList;
	vector<string> data;

	public:
		Trie(){
			headList.assign(CHARS, NULL);
		}

		void insert(string s, int id){
			int ch = s[0]-'a';
			int n = s.length();
			TrieNode* p;
			int i;

			if(headList[ch] == NULL){
				headList[ch] = new TrieNode(s[0], id);
			}

			p = headList[ch];

			for(i=1; i<n; ++i){
				ch = s[i] - 'a';
				if(p->children[ch] == NULL){
					p->children[ch] = new TrieNode(s[i], id);
				}
				p = p->children[ch];
			}
			// ch will store the last element of string after loop
			p->makeEnd(id);

			data.pb(s);
		}

		string query(string s, int r){
			string str = "";
			int n = s.length();
			TrieNode* p;
			int ch = s[0]-'a';
			int i, j;

			// if no string has a matchin prefix
			if(headList[ch]==NULL){
				return minString(r);
			}

			if(headList[ch]->firstApp > r){
				return minString(r);
			}

			p = headList[ch];
			str += s[0];
			for(i=1; i<n; ++i){
				ch = s[i] - 'a';
				if(p->children[ch] == NULL){
					break;
				}
				else{
					if(p->children[ch]->firstApp <= r){
						p = p->children[ch];
						str += p->name;
					}
					else{
						break;
					}
				}
			}

			while((p->isEnd == false) || (p->endId > r)){
				for(i=0; i<CHARS; ++i){
					if(p->children[i] == NULL)
						continue;
					if(p->children[i]->firstApp > r)
						continue;

					p = p->children[i];
					str += p->name;
					break;
				}
			}
			return str;
		}

		string minString(int r){
			string s = data[0];
			int i;
			for(i=1; i<=r; ++i){
				if(data[i] < s){
					s = data[i];
				}
			}
			return s;
		}
};

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	string str;
	int q, r, i;
	Trie head;

	cin >> n;
	for(i=0; i<n; ++i){
		cin >> str;
		head.insert(str, i);
	}

	cin >> q;
	for(i=0; i<q; ++i){
		cin >> r;
		cin >> str;
		// use 0 indexing for query
		cout << head.query(str, r-1) << endl;
	}

	return 0;
}
