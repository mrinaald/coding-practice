#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <functional> 	// for std::greater

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

struct Seat{
	int width;
	int id;

	Seat(){
		width = 0;
		id = -1;
	}

	Seat(int w, int i){
		width = w;
		id = i;
	}
};

class min_heap_comparator{
	public:
		int operator() (const Seat& lhs, const Seat& rhs){
			return lhs.width > rhs.width;
		}
};

class max_heap_comparator{
	public:
		int operator() (const Seat& lhs, const Seat& rhs){
			return lhs.width < rhs.width;
		}
};

int main(){
	std::ios::sync_with_stdio(false);

	// Default min/max - heaps
	// priority_queue<int, vector<int>, greater<int> > min_heap;
	// priority_queue<int> max_heap;

	priority_queue<Seat, vector<Seat>, min_heap_comparator > min_heap;
	priority_queue<Seat, vector<Seat>, max_heap_comparator > max_heap;

	int n;
	int i, w;
	string in_str;

	cin >> n;

	for(i=0; i<n; ++i){
		cin >> w;
		Seat ns(w, i+1);
		min_heap.push(ns);
	}

	cin >> in_str;

	int len = in_str.length();

	vector<int> indices;
	for(i=0; i<len; ++i){
		if(in_str[i] == '0'){
			Seat s = min_heap.top();
			indices.pb(s.id);
			max_heap.push(s);
			min_heap.pop();
		}
		else if(in_str[i] == '1'){
			Seat s = max_heap.top();
			indices.pb(s.id);
			max_heap.pop();
		}
	}

	for(i=0; i<len; ++i){
		cout << indices[i] << ' ' ;
	}
	cout << endl;

	// cout << "Min Heap: ";
	// for(i=0; i<n; ++i){
	//     cout << min_heap.top().width << ' ';
	//     min_heap.pop();
	// }
	// cout << endl;

	// cout << "Max Heap: ";
	// for(i=0; i<n; ++i){
	//     cout << max_heap.top().width << ' ';
	//     max_heap.pop();
	// }
	// cout << endl;

	return 0;
}
