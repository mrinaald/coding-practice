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


#define MAX_STEPS 2000000000

int make_pieces_equal(map<std::pair<int, int>, int>& dp, int a, int b) {
    if (a == b) {
        return 0;
    }

    std::pair<int, int> i = mp(a, b);
    if (dp.find(i) != dp.end()) {
        return dp[i];
    }

    if (a > b) {
        int s2, s3, s5;
        s2 = s3 = s5 = -1;

        if (a % 2 == 0) {
            // s2 = make_pieces_equal(dp, a / 2, b, steps + 1);
            s2 = make_pieces_equal(dp, a / 2, b);
        }
        if (a % 3 == 0) {
            // s3 = make_pieces_equal(a / 3, b, steps + 1);
            s3 = make_pieces_equal(dp, a / 3, b);
        }
        if (a % 5 == 0) {
            // s5 = make_pieces_equal(a / 5, b, steps + 1);
            s5 = make_pieces_equal(dp, a / 5, b);
        }

        if (s2 == -1 && s3 == -1 && s5 == -1) {
            dp[i] = -1;
            return -1;
        } else {
            if (s2 == -1){
                s2 = MAX_STEPS;
            }
            if (s3 == -1){
                s3 = MAX_STEPS;
            }
            if (s5 == -1){
                s5 = MAX_STEPS;
            }
            // return min(min(s2, s3), s5);
            dp[i] = 1 + min(min(s2, s3), s5);
            return dp[i];
        }
    } else {
        int s2, s3, s5;
        s2 = s3 = s5 = -1;

        if (b % 2 == 0) {
            // s2 = make_pieces_equal(a, b / 2, steps + 1);
            s2 = make_pieces_equal(dp, a, b / 2);
        }
        if (b % 3 == 0) {
            // s3 = make_pieces_equal(a, b / 3, steps + 1);
            s3 = make_pieces_equal(dp, a, b / 3);
        }
        if (b % 5 == 0) {
            // s5 = make_pieces_equal(a, b / 5, steps + 1);
            s5 = make_pieces_equal(dp, a, b / 5);
        }

        if (s2 == -1 && s3 == -1 && s5 == -1) {
            dp[i] = -1;
            return -1;
        } else {
            if (s2 == -1){
                s2 = MAX_STEPS;
            }
            if (s3 == -1){
                s3 = MAX_STEPS;
            }
            if (s5 == -1){
                s5 = MAX_STEPS;
            }
            // return min(min(s2, s3), s5);
            dp[i] = 1 + min(min(s2, s3), s5);
            return dp[i];
        }
    }
}

int main(){
    // - Use cin, cout for Faster I/O.
    // - Use cout << endl only when you want to flush the output forcefully
    // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    map<std::pair<int, int>, int> dp;
    cout << make_pieces_equal(dp, a, b) << "\n";
    cout << std::flush;
    return 0;
}
