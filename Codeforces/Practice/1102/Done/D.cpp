#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int abs(const int x) {
  return (x >= 0) ? x : -x;
}

void try_and_fix(string &str, vector<int> &count, int index);
void try_and_fix_0(string &str, vector<int> &count);
void try_and_fix_1(string &str, vector<int> &count);
void try_and_fix_2(string &str, vector<int> &count);

int main(){
  // std::ios::sync_with_stdio(false);
  int n, i;
  string str;
  int len;
  vector<int> count(3);

  scanf("%d", &n);
  cin >> str;

  len = str.length();

  for (i=0; i<len; ++i) {
    count[str[i] - '0'] += 1;
  }

  for (i=0; i<3; ++i)
    count[i] -= (n / 3);

  for (i=0; i<3; ++i) {
    if (count[i] > 0) {
      try_and_fix(str, count, i);
    }
  }

  cout << str << endl;

  return 0;
}


void try_and_fix(string &str, vector<int> &count, int index) {
  switch(index) {
  case 0: try_and_fix_0(str, count); break;
  case 1: try_and_fix_1(str, count); break;
  case 2: try_and_fix_2(str, count); break;
  default: break;
  }
}


void try_and_fix_0(string &str, vector<int> &count){
  int my_index = 0;
  int my_char = '0';
  int i;
  int num_to_change;
  size_t s = str.length()-1;

  for (i=2; i>=1; --i) {
    if (count[i] >= 0)
      continue;

    num_to_change = min(count[my_index], abs(count[i]));

    for (; (s >= 0) && (num_to_change > 0); --s) {
      if (str[s] == my_char) {
        str[s] = i + '0';
        --num_to_change;
      }
    }

    count[my_index] -= num_to_change;
    count[i] += num_to_change;

    if (count[my_index] == 0)
      break;
  }
}


void try_and_fix_1(string &str, vector<int> &count){
  int my_index = 1;
  int my_char = '1';
  int num_to_change;
  size_t s = 0;
  int candidate;

  candidate = 0;
  if (count[candidate] < 0) {
    num_to_change = min(count[my_index], abs(count[candidate]));

    for (; (s < str.length()) && (num_to_change > 0); ++s) {
      if (str[s] == my_char) {
        str[s] = candidate + '0';
        --num_to_change;
      }
    }

    count[my_index] -= num_to_change;
    count[candidate] += num_to_change;
  }

  if (count[my_index] == 0)
    return;

  candidate = 2;
  if (count[candidate] < 0) {
    num_to_change = min(count[my_index], abs(count[candidate]));

    for (s = str.length()-1; (s >= 0) && (num_to_change > 0); --s) {
      if (str[s] == my_char) {
        str[s] = candidate + '0';
        --num_to_change;
      }
    }

    count[my_index] -= num_to_change;
    count[candidate] += num_to_change;
  }
}


void try_and_fix_2(string &str, vector<int> &count){
  int my_index = 2;
  int my_char = '2';
  int i;
  int num_to_change;
  size_t s = 0;

  for (i=0; i<=1; ++i) {
    if (count[i] >= 0)
      continue;

    num_to_change = min(count[my_index], abs(count[i]));

    for (; (s < str.length()) && (num_to_change > 0); ++s) {
      if (str[s] == my_char) {
        str[s] = i + '0';
        --num_to_change;
      }
    }

    count[my_index] -= num_to_change;
    count[i] += num_to_change;

    if (count[my_index] == 0)
      break;
  }
}
