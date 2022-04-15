#include <iostream>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;


bool my_comparator(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first <= rhs.first;
}

int main(){
    // - Use cin, cout for Faster I/O.
    // - Use cout << endl only when you want to flush the output forcefully
    // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v;
    cin >> n >> v;

    int i;
    int a, b;
    int min_day = 5000;
    int max_day = -1;
    map<int, int> trees;
    for (i=0; i<n; ++i) {
        cin >> a >> b;
        if (trees.find(a) == trees.end()) {
            trees.insert(mp(a, 0));
        }
        trees[a] += b;
        min_day = min(min_day, a);
        max_day = max(max_day, a);
    }
    max_day++;

    llong max_fruits = 0;
    int x, fruits_can_collect;
    for (int d=min_day; d<=max_day; ++d) {
        fruits_can_collect = v;

        if (trees.find(d-1) != trees.end()) {
            x = min(trees[d-1], fruits_can_collect);
            trees[d-1] -= x;
            fruits_can_collect -= x;
            max_fruits += x;
        }

        if (trees.find(d) != trees.end()) {
            x = min(trees[d], fruits_can_collect);
            trees[d] -= x;
            fruits_can_collect -= x;
            max_fruits += x;
        }
    }

    cout << max_fruits;

    cout << std::flush;
    return 0;
}
