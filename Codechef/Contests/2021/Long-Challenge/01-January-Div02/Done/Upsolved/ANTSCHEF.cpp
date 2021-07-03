/*
 * Problem upsolved after the contest.
 * Editorial: https://discuss.codechef.com/t/antschef-editorial/83327
 */
#include <iostream>
#include <vector>
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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  int n, m;
  int i, j;
  int x;
  ullong left, right;
  ullong ans;
  while (t--) {
    cin >> n;

    if (n == 1) {
      left = right = 0;
      cin >> m;
      for (i=0; i<m; ++i) {
        cin >> x;
        if (x < 0)
          ++left;
        else
          ++right;
      }

      cout << left * right << "\n";
      continue;
    }

    vector<int> num_neg(n, 0);
    vector<int> num_pos(n, 0);
    map<int, vector<pair<int, bool>>> distance;
    bool is_neg;

    for (i=0; i<n; ++i) {
      cin >> m;
      for (j=0; j<m; ++j) {
        cin >> x;

        if (x > 0) {
          num_pos[i]++;
          is_neg = false;
        }
        else {
          num_neg[i]++;
          is_neg = true;
        }

        x = abs(x);
        distance[x].pb(mp(i, is_neg));
      }
    }

    ans = 0;
    for (auto it = distance.begin(); it != distance.end(); ++it) {
      if (it->second.size() > 1) {
        // ants are colliding at O
        ans++;

        for (i=0; i < it->second.size(); ++i) {
          n = it->second[i].first;
          is_neg = it->second[i].second;

          if (is_neg) {
            if (num_neg[n] > 0)
              ans += (num_neg[n] - 1);
            num_neg[n]--;
          }
          else {
            if (num_pos[n] > 0)
              ans += (num_pos[n] - 1);
            num_pos[n]--;
          }
        }
      }
      else if (it->second.size() == 1) {
        // ant did not collide at O
        n = it->second[0].first;
        is_neg = it->second[0].second;

        if (is_neg) {
          if (num_pos[n] > 0)
            ans += num_pos[n];
          num_neg[n]--;
        }
        else {
          if (num_neg[n] > 0)
            ans += num_neg[n];
          num_pos[n]--;
        }
      }
    }

    cout << ans << "\n";
  }

  cout << std::flush;
  return 0;
}
