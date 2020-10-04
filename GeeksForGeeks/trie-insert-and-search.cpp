#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

#define ALPHABET_SIZE 26

using namespace std;

struct TRIE
{
	struct TRIE *children[ALPHABET_SIZE];
	bool leafNode;
};

stack<char> word;

TRIE* CreateTRIE(int n);
short Search(TRIE *root, string q);
TRIE* Insert(TRIE* root, string key);
TRIE* CreateNewNode();
void printTRIE(TRIE *root);
void printStack();

int main() 
{
	std::ios::sync_with_stdio(false);
	int t, n;
	cin >>t;

	while(t--)
	{
		cin >> n;
		TRIE *root = NULL;
		root = CreateTRIE(n);

		string q;
		cin >> q;
		// cout << q << " received\n";
		cout << Search(root, q) << endl;
	}
	return 0;
}

TRIE* CreateTRIE(int n)
{
	int t = n;
	TRIE *root = NULL;

	while(t--)
	{
		string key;
		cin >> key;
		// cout << key << " inserted\n";
		// int size = key.size();

		root = Insert(root, key);
		int idx = key[0] - 'a';
	}

	return root;
}

TRIE* Insert(TRIE* root, string key)
{
	if(root==NULL)
	{
		root = CreateNewNode();

		TRIE *r = root;
		int size = key.size();
		
		for(int i=0; i<size; ++i)
		{
			int idx = key[i]-'a';
			TRIE *ptr = CreateNewNode();
			r->children[idx] = ptr;
			r = ptr;
		}
		r->leafNode = true;

		return root;
	}
	else
	{
		int size = key.size();
		TRIE *r = root;

		for(int i=0; i<size; ++i)
		{
			int idx = key[i]-'a';
			if(r->children[idx]!=NULL)
			{
				if(i!=(size-1))
					r = r->children[idx];
				continue;
			}
			else
			{
				TRIE *ptr = CreateNewNode();
				r->children[idx] = ptr;
				r= ptr;
			}
		}
		r->leafNode = true;

		return root;
		
	}
}

TRIE* CreateNewNode()
{
	TRIE *ptr = new TRIE;
		
	for(int i=0; i<ALPHABET_SIZE; ++i)
		ptr->children[i] = NULL;

	ptr->leafNode = false;

	return ptr;
}

short Search(TRIE *root, string q)
{
	// printTRIE(root);
	bool flag = false;

	int size = q.size();

	TRIE *r = root;
	// printTRIE(r);

	for(int i=0; i<size; ++i)
	{
		int idx = q[i]-'a';
		if(r->children[idx]==NULL)
		{
			flag = false;
			break;
		}
		// if(i==(size-1))
		// {
		// 	flag = r->leafNode;
		// }

		r = r->children[idx];
	}
	flag = r->leafNode;

	if(flag)
		return 1;
	else
		return 0;
}

void printTRIE(TRIE *root)
{
	if(root->leafNode)
		printStack();

	for(int i=0; i<ALPHABET_SIZE; ++i)
	{
		if(root->children[i] != NULL)
		{
			char ch = ( (char) i+'a');
			word.push(ch);
			printTRIE(root->children[i]);
			word.pop();
		}
	}
}
	
void printStack()
{
	stack<char> p(word);
	string str;

	while(!p.empty())
	{
		char ch = p.top();
		p.pop();
		// cout << ch;
		str.push_back(ch);
	}
	reverse(str.begin(), str.end());
	cout << str;
	cout << '\n';
}