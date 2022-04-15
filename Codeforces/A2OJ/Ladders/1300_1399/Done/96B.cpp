#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int get_digits(int n) {
    int digits = 0;
    while (n > 0) {
        digits++;
        n /= 10;
    }
    return digits;
}

llong get_number(vector<int>& digits) {
    llong number = 0;
    for (int i=0; i<digits.size(); ++i) {
        number = (number * 10) + digits[i];
    }
    return number;
}

int main(){
    // - Use cin, cout for Faster I/O.
    // - Use cout << endl only when you want to flush the output forcefully
    // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int digits = get_digits(n);
    vector<llong> super_lucky;

    int i, j;
    for (i=2; i<=digits+2; i+=2) {
        vector<int> arr;
        for (j=1; j<=i/2; ++j) {
            arr.pb(4);
            arr.pb(7);
        }

        sort(all(arr));

        do {
            super_lucky.pb(get_number(arr));
        } while(next_permutation(all(arr)));
    }

    // for (i=0; i<super_lucky.size(); ++i) {
    //     cout << super_lucky[i] << endl;
    // }

    vector<llong>::iterator next_super_lucky;
    next_super_lucky = lower_bound(all(super_lucky), n); // finding lowest index s.t. super_lucky[i] >= n

    cout << *next_super_lucky << endl;

    cout << std::flush;
    return 0;
}
