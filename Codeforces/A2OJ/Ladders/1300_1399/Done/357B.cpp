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

int main(){
    // - Use cin, cout for Faster I/O.
    // - Use cout << endl only when you want to flush the output forcefully
    // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int i;
    int d1, d2, d3;
    vector<bool> wrb(4, false);
    vector<int> colors(n+1, 0);

    while (m--) {
        for (i=1; i<4; ++i) {
            wrb[i] = false;
        }

        cin >> d1 >> d2 >> d3;

        // Check which colors are already assigned to some dancer
        if (colors[d1] != 0) {
            wrb[colors[d1]] = true;
        }
        if (colors[d2] != 0) {
            wrb[colors[d2]] = true;
        }
        if (colors[d3] != 0) {
            wrb[colors[d3]] = true;
        }

        // Assign the colors which are not yet used in this dance
        if (colors[d1] == 0) {
            for (i=1; i<4; ++i) {
                if (wrb[i] == false) {
                    colors[d1] = i;
                    wrb[i] = true;
                    break;
                }
            }
        }

        if (colors[d2] == 0) {
            for (i=1; i<4; ++i) {
                if (wrb[i] == false) {
                    colors[d2] = i;
                    wrb[i] = true;
                    break;
                }
            }
        }

        if (colors[d3] == 0) {
            for (i=1; i<4; ++i) {
                if (wrb[i] == false) {
                    colors[d3] = i;
                    wrb[i] = true;
                    break;
                }
            }
        }
    }

    for (i=1; i<=n; ++i) {
        cout << colors[i] << " ";
    }
    cout << "\n";

    cout << std::flush;
    return 0;
}
