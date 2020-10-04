#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define M 1000000007

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct Number {
  vector<map<ullong, Number>::iterator> multiples;
  ullong divisors;
  ullong vec_id;
};

ullong p, q;
map<ullong, Number> dp;
vector<map<ullong, Number>::iterator> it_vec;

ullong gcd(ullong a, ullong b);
void find_divisors(const ullong n);
void find_expectation(const ullong n, const int k);
void find_probabilities(vector< std::pair<ullong, ullong> > &prob, const ullong n, const int k);
void add_fractions(const ullong num1, const ullong den1, const ullong num2, const ullong den2, ullong &num, ullong &den);
void insert_divisors(const ullong lf, const ullong rf);
void print_data(const vector< std::pair<ullong, ullong> > &probability);
void print_result();

int main(){
  // std::ios::sync_with_stdio(false);
  ullong n;
  int k;

  scanf("%llu %d", &n, &k);

  find_divisors(n);

  find_expectation(n, k);

  print_result();

  return 0;
}

ullong gcd(ullong a, ullong b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

void insert_divisors(const ullong lf, const ullong rf) {
  Number num;
  map<ullong, Number>::iterator it;
  llong i;

  dp[lf] = num;
  it = dp.find(lf);
  it->second.multiples.pb(it);
  it->second.divisors = 1;
  it->second.vec_id = it_vec.size();

  // finding divisors of lf from list of already found divisors of n
  i = it_vec.size();
  i -= 2;
  while (i >= 0) {
    if ( lf % it_vec[i]->first == 0) {
      it_vec[i]->second.multiples.pb(it);
      it->second.divisors += 1;
    }
    i -= 2;
  }

  // finding multiples of lf from list of already found divisors of n
  i = it_vec.size();
  i -= 1;
  while (i >= 0) {
    if ( it_vec[i]->first % lf == 0) {
      it->second.multiples.pb(it_vec[i]);
      it_vec[i]->second.divisors += 1;
    }
    i -= 2;
  }
  it_vec.pb(it);

  if (lf == rf)
    return;

  dp[rf] = num;
  it = dp.find(rf);
  it->second.multiples.pb(it);
  it->second.divisors = 1;
  it->second.vec_id = it_vec.size();

  // finding divisors of rf from list of already found divisors of n
  i = it_vec.size();
  i -= 1;
  while (i >= 0) {
    if ( rf % it_vec[i]->first == 0) {
      it_vec[i]->second.multiples.pb(it);
      it->second.divisors += 1;
    }
    i -= 2;
  }

  // finding multiples of rf from list of already found divisors of n
  i = it_vec.size();
  i -= 2;
  while (i >= 0) {
    if ( it_vec[i]->first % rf == 0) {
      it->second.multiples.pb(it_vec[i]);
      it_vec[i]->second.divisors += 1;
    }
    i -= 2;
  }
  it_vec.pb(it);
}

void find_divisors(const ullong n) {
  ullong lim = (ullong) sqrt(n);
  ullong lf, rf;

  lf = 1;
  rf = n;

  insert_divisors(lf, rf);

  lf = 2;
  for (; lf <= lim; ++lf) {
    if (n%lf != 0)
      continue;
    rf = n / lf;
    insert_divisors(lf, rf);
  }
}

void add_fractions_2(const ullong num1, const ullong den1, const ullong num2, const ullong den2, ullong &num, ullong &den) {
  ullong d = den1 * den2;
  ullong n = (num1 * den2) + (num2 * den1);

  printf(" ** num1 / den1: %llu / %llu\n", num1, den1);
  printf(" ** num2 / den2: %llu / %llu\n", num2, den2);
  printf(" ** n / d      : %llu / %llu\n", n, d);

  ullong g = gcd(d, n);

  num = n / g;
  den = d / g;
}

void find_probabilities(vector< std::pair<ullong, ullong> > &prob, const ullong n, const int k) {
  vector<vector< std::pair<ullong, ullong> >> aux_prob(2);

  short old = 0;
  short curr = old ^ 1;
  aux_prob[old] = prob;
  aux_prob[curr] = prob;    // only for size initialization

  size_t vec_size = it_vec.size();
  size_t i;
  size_t j;
  size_t m_size;
  map<ullong, Number>::iterator m;
  ullong g;
  ullong num, tnum;
  ullong den, tden;

  for (int _k=2; _k<=k; ++_k, old = old^1) {
    curr = old ^ 1;

    for (i=0; i<vec_size; ++i) {
      m_size = it_vec[i]->second.multiples.size();

      num = 0;
      den = 1;
      bool flag = true;
      for (j=0; j<m_size; ++j) {
        m = it_vec[i]->second.multiples[j];

        tnum = aux_prob[old][m->second.vec_id].first;
        tden = aux_prob[old][m->second.vec_id].second * m->second.divisors;
        if (tden == 0) {
          printf("tden\n");
          printf("old den: %llu \n", aux_prob[old][m->second.vec_id].second);
          printf("divisors: %llu \n", m->second.divisors);
        }

        g = gcd(tden, tnum);
        tnum /= g;
        tden /= g;

        // if (den == 0) {
        //   printf("den\n");
        // }
        // if (tden == 0) {
        //   printf("tden\n");
        // }
        ullong x = num;
        ullong y = den;
        add_fractions(num, den, tnum, tden, num, den);
        if (flag && den == 0) {
          printf(" * before add %ld: %llu / %llu  +  %llu / %llu\n", j, x, y, tnum, tden);
          printf(" * after add %ld: %llu / %llu\n", j, num, den);
          add_fractions_2(x, y, tnum, tden, x, y);
          flag = false;
        }
      }

      aux_prob[curr][i].first = num;
      aux_prob[curr][i].second = den;
      if ((aux_prob[old][it_vec[i]->second.vec_id].second != 0) &&
          (aux_prob[curr][it_vec[i]->second.vec_id].second == 0)) {
        // something is wrong... start debugging ohahahahaha
        printf(" * k: %d  n: %llu\n", _k, it_vec[i]->first);
        printf(" * old prob: %llu / %llu\n", aux_prob[old][it_vec[i]->second.vec_id].first, aux_prob[old][it_vec[i]->second.vec_id].second);
        printf(" * curr prob: %llu / %llu\n", aux_prob[curr][it_vec[i]->second.vec_id].first, aux_prob[curr][it_vec[i]->second.vec_id].second);
        printf("\n");
      }
    }
  }

  prob = aux_prob[old];
}

void find_expectation(const ullong n, const int k) {
  if (it_vec.size() == 1) {
    // this means n == 1
    p = q = 1;
    return;
  }

  ullong divs = it_vec[1]->second.divisors;

  vector< std::pair<ullong, ullong> > probability(it_vec.size(), mp(1, divs));
  find_probabilities(probability, n, k);

  ullong g;
  ullong num, tnum;
  ullong den, tden;
  size_t i;
  size_t it_vec_size = it_vec.size();

  num = 0;
  den = 1;
  for (i=0; i<it_vec_size; ++i) {
    tnum = it_vec[i]->first * probability[i].first;
    tden = probability[i].second;

    g = gcd(tden, tnum);
    tnum /= g;
    tden /= g;

    add_fractions(num, den, tnum, tden, num, den);
  }

  p = num;
  q = den;

  // print_data(probability);
}

void add_fractions(const ullong num1, const ullong den1, const ullong num2, const ullong den2, ullong &num, ullong &den) {
  ullong d = den1 * den2;
  ullong n = (num1 * den2) + (num2 * den1);

  ullong g = gcd(d, n);

  num = n / g;
  den = d / g;
}

void print_data(const vector< std::pair<ullong, ullong> > &probability) {
  auto it = dp.begin();
  for (; it != dp.end(); it++) {
    printf(" * %llu\n", it->first);
    printf(" ** It_vec index: %llu\n", it->second.vec_id);
    printf(" ** #Divisors: %llu\n", it->second.divisors);
    printf(" ** Multiples: ");
    for (ullong i=0; i < it->second.multiples.size(); ++i) {
      printf("%llu ", it->second.multiples[i]->first);
    }
    printf("\n");
    printf(" ** Final Probability = %llu / %llu", probability[it->second.vec_id].first, probability[it->second.vec_id].second);
    printf("\n\n");
  }
}

ullong my_pow(ullong x, ullong n, ullong mod) {
  if (x == 1)
    return 1;
  if (n == 0)
    return 1;
  if (n == 1)
    return x % mod;

  ullong temp = my_pow(x, n/2, mod) % mod;
  temp = ((temp % mod) * (temp % mod)) % mod;

  if (n & 1) {
    temp = ((temp % mod) * (x % mod)) % mod;
  }

  return temp;
}

void print_result() {
  // printf("p: %llu\n", p);
  // printf("q: %llu\n", q);
  ullong q_inv = my_pow(q, M-2, M);

  ullong ans = ((p % M) * (q_inv % M)) % M;

  printf("%llu\n", ans);
}
