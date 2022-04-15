#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

bool is_proper_intersection(vector<pair<int, int>>& circles, pair<int, int>& p2) {
    // proper intersection in this context is defined between two sets A, B as the case
    // where both (A - intersection(A, B)) and (B - intersection(A, B)) are not null/empty.
    pair<int, int> p1;
    for (int i=0; i<circles.size(); ++i) {
        p1 = circles[i];
        if (p1.first < p2.first && p2.first < p1.second && p1.second < p2.second) {
            return true;
        }
        if (p2.first < p1.first && p1.first < p2.second && p2.second < p1.second) {
            return true;
        }
    }

    return false;
}

int main(){
    // - Use cin, cout for Faster I/O.
    // - Use cout << endl only when you want to flush the output forcefully
    // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> circles;
    int i;
    int a, b;
    pair<int, int> p;
    bool has_self_intersection = false;

    cin >> a;
    for (i=1; i<n; ++i) {
        cin >> b;
        p = mp(min(a, b), max(a, b));

        if (is_proper_intersection(circles, p)) {
            has_self_intersection = true;
        }

        circles.pb(p);
        a = b;
    }

    cout << ((has_self_intersection) ? "yes\n" : "no\n");
    cout << std::flush;
    return 0;
}
