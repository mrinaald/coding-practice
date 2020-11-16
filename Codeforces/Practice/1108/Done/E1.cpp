/*
 * Solution done with tutorial's help
 */
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

#define MIN_SCORE -10000000

int compute_score(const vector<int>& arr);
void compute_diff_arr(const vector<int>& src, vector<int>& dest);

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int i, j;
  int n, m;
  cin >> n >> m;


  vector<int> arr(n, 0);
  for (i=0; i<n; ++i) {
    cin >> arr[i];
  }

  vector<std::pair<int, int>> segments(m);
  for (i=0; i<m; ++i) {
    cin >> segments[i].first >> segments[i].second;
    segments[i].first--;
    segments[i].second--;
  }

  vector<int> result(n);
  vector<int> final_queries;
  std::pair<int, int> *seg;
  int max_score = MIN_SCORE;
  int score;

  for (i=0; i<n; ++i) {
    compute_diff_arr(arr, result);
    if (max_score == MIN_SCORE)
      max_score = compute_score(result);

    vector<int> temp_queries;
    for (j=0; j<m; ++j) {
      seg = &(segments[j]);
      if ((seg->first <= i) && (i <= seg->second))
        continue;

      temp_queries.pb(j + 1);
      result[seg->first] -= 1;
      if ((seg->second + 1) < n)
        result[seg->second + 1] += 1;
    }

    score = compute_score(result);
    if (score > max_score) {
      max_score = score;
      if (final_queries.size() > 0)
        final_queries.clear();
      final_queries.insert(final_queries.begin(), all(temp_queries));
    }
  }

  cout << max_score << "\n" << final_queries.size() << "\n";
  for (i=0; i<final_queries.size(); ++i) {
    cout << final_queries[i] << " ";
  }
  cout << "\n";

  return 0;
}

int compute_score(const vector<int>& arr) {
  int max_a = arr[0];
  int min_a = arr[0];
  int prev_a = arr[0];
  int a;

  for (size_t i=1; i<arr.size(); ++i) {
    a = arr[i] + prev_a;
    prev_a = a;
    if (a > max_a)
      max_a = a;
    if (a < min_a)
      min_a = a;
  }

  return max_a - min_a;
}

void compute_diff_arr(const vector<int>& src, vector<int>& dest) {
  for (size_t i=0; i<src.size(); ++i) {
    if (i > 0)
      dest[i] = src[i] - src[i-1];
    else
      dest[i] = src[i];
  }
}
