#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_CHARS 26

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, i, j;
  int p, p1, p2;
  string suf, suf1, suf2;
  llong t1, t2;
  llong team_names;

  cin >> t;
  while (t--) {
    cin >> n;

    vector<string> words(n);
    vector<int> pref_count(MAX_CHARS, 0);
    unordered_set<string> suffixes;
    vector<set<string>> pref_to_suf(MAX_CHARS, set<string>());
    unordered_map<string, vector<bool>> suf_to_pref;
    for (i=0; i<n; ++i) {
      cin >> words[i];

      p = words[i][0] - 'a';
      pref_count[p]++;

      suf = words[i].substr(1, words[i].length());
      suffixes.insert(suf);

      pref_to_suf[p].insert(suf);

      if (suf_to_pref.find(suf) == suf_to_pref.end()) {
        suf_to_pref.insert(mp(suf, vector<bool>(MAX_CHARS, false)));
      }
      suf_to_pref[suf][p] = true;
    }

    team_names = 0;
    for (p1=0; p1<MAX_CHARS; ++p1) {
      if (pref_count[p1] == suffixes.size() || pref_count[p1] == 0)
        continue;

      // t1 = ((int)suffixes.size() - pref_count[p1]);

      for (p2=p1+1; p2<MAX_CHARS; ++p2) {
        if (pref_count[p2] == suffixes.size() || pref_count[p2] == 0)
          continue;

        // t2 = ((int)suffixes.size() - pref_count[p2]);
        t1 = t2 = 0;
        for (auto s1 : pref_to_suf[p1]) {
          if (suf_to_pref[s1][p2] == false)
            ++t2;
        }

        for (auto s2 : pref_to_suf[p2]) {
          if (suf_to_pref[s2][p1] == false)
            ++t1;
        }

        team_names += (t1 * t2);
      }
    }
    // for (i=0; i<MAX_CHARS; ++i) {
    //   if (pref_count[i] == suffixes.size() || pref_count[i] == 0)
    //     continue;
    //   p1 = pref_count[i];

    //   for (j=i+1; j<MAX_CHARS; ++j) {
    //     if (pref_count[j] == suffixes.size() || pref_count[j] == 0)
    //       continue;
    //     p2 = pref_count[j];

    //     t2 = 0;
    //     for (auto s : pref_to_suf[i]) {
    //       if (suf_to_pref[s][j] == false)
    //         t2++;
    //     }

    //     team_names += (p1 * t2);
    //   }
    // }

    cout << 2*team_names << "\n";
  }

  cout << std::flush;
  return 0;
}
