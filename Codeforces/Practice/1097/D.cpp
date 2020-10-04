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
  ullong num;
  vector<Number*> multiples;
  ullong divisors;
  ullong divisors_inv = 0;
  ullong factor_index;
};

ullong final_expectation = 0;
vector<Number*> factors;
Number NumberPool[100000];
ullong NumberPoolIndex = 0;

void find_divisors(const ullong n);
void find_expectation(const ullong n, const int k);
void find_probabilities(vector<ullong> &prob, const ullong n, const int k);
void compute_div_invs();
void insert_divisors(const ullong lf, const ullong rf);
ullong mod_inv(ullong x, ullong n, ullong mod);
void print_data(const vector<ullong> &probability);
Number* create_new_number();

int main(){
  // std::ios::sync_with_stdio(false);
  ullong n;
  int k;

  scanf("%llu %d", &n, &k);

  find_divisors(n);

  find_expectation(n, k);

  printf("%llu\n", final_expectation % M);

  return 0;
}

void insert_divisors(const ullong lf, const ullong rf) {
  Number* num_ptr = new Number();
  llong i;

  num_ptr->num = lf;
  num_ptr->factor_index = factors.size();
  num_ptr->multiples.pb(num_ptr);
  num_ptr->divisors = 1;
  num_ptr->divisors_inv = 0;

  // finding divisors of lf from list of already found divisors of n
  i = factors.size();
  i -= 2;
  while (i >= 0) {
    if ( lf % factors[i]->num == 0) {
      factors[i]->multiples.pb(num_ptr);
      num_ptr->divisors += 1;
    }
    i -= 2;
  }

  // finding multiples of lf from list of already found divisors of n
  i = factors.size();
  i -= 1;
  while (i >= 0) {
    if ( factors[i]->num % lf == 0) {
      num_ptr->multiples.pb(factors[i]);
      factors[i]->divisors += 1;
    }
    i -= 2;
  }
  factors.pb(num_ptr);


  if (lf == rf)
    return;

  num_ptr = new Number();
  num_ptr->num = rf;
  num_ptr->factor_index = factors.size();
  num_ptr->multiples.pb(num_ptr);
  num_ptr->divisors = 1;
  num_ptr->divisors_inv = 0;

  // finding divisors of rf from list of already found divisors of n
  i = factors.size();
  i -= 1;
  while (i >= 0) {
    if ( rf % factors[i]->num == 0) {
      factors[i]->multiples.pb(num_ptr);
      num_ptr->divisors += 1;
    }
    i -= 2;
  }

  // finding multiples of rf from list of already found divisors of n
  i = factors.size();
  i -= 2;
  while (i >= 0) {
    if ( factors[i]->num % rf == 0) {
      num_ptr->multiples.pb(factors[i]);
      factors[i]->divisors += 1;
    }
    i -= 2;
  }
  factors.pb(num_ptr);
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

void find_probabilities(vector<ullong> &prob, const ullong n, const int k) {
  vector<vector<ullong>> aux_prob(2);

  short old = 0;
  short curr = old ^ 1;
  aux_prob[old] = prob;
  aux_prob[curr] = prob;    // only for size initialization

  size_t vec_size = factors.size();
  size_t i;
  size_t j;
  size_t m_size;
  Number* m;
  ullong curr_prob;
  ullong m_prob;

  for (int _k=2; _k<=k; ++_k, old = old^1) {
    curr = old ^ 1;

    for (i=0; i<vec_size; ++i) {
      m_size = factors[i]->multiples.size();

      curr_prob = 0;
      for (j=0; j<m_size; ++j) {
        m = factors[i]->multiples[j];

        m_prob = ((aux_prob[old][m->factor_index] % M) * (m->divisors_inv % M)) % M;
        curr_prob = ((curr_prob % M) + (m_prob % M)) % M;
      }

      aux_prob[curr][i] = curr_prob;
    }
  }

  prob = aux_prob[old];
}

void find_expectation(const ullong n, const int k) {
  if (factors.size() == 1) {
    // this means n == 1
    final_expectation = 1;
    return;
  }

  compute_div_invs();

  // n is stored at index 1 in factors vector
  vector<ullong> probability(factors.size(), factors[1]->divisors_inv);
  find_probabilities(probability, n, k);

  size_t i;
  size_t factors_size = factors.size();
  ullong expec = 0;
  ullong i_expec;

  for (i=0; i<factors_size; ++i) {
    i_expec = ((factors[i]->num % M) * (probability[i] % M)) % M;
    expec = ((expec % M) + (i_expec % M)) % M;
  }

  final_expectation = expec;

  // print_data(probability);
}

void print_data(const vector<ullong> &probability) {
  size_t i;
  for (i=0; i<factors.size(); ++i) {
      printf(" * %llu\n", factors[i]->num);
      printf(" ** factors index: %llu\n", factors[i]->factor_index);
      printf(" ** #Divisors: %llu\n", factors[i]->divisors);
      printf(" ** Multiples: ");
      for (ullong i=0; i < factors[i]->multiples.size(); ++i) {
        printf("%llu ", factors[i]->multiples[i]->num);
      }
      printf("\n");
      printf(" ** Final Probability Modulo Inverse = %llu", probability[factors[i]->factor_index]);
      printf("\n\n");
  }
  // auto it = dp.begin();
  // for (; it != dp.end(); it++) {
  //   printf(" * %llu\n", it->first);
  //   printf(" ** factors index: %llu\n", it->second.factor_index);
  //   printf(" ** #Divisors: %llu\n", it->second.divisors);
  //   printf(" ** Multiples: ");
  //   for (ullong i=0; i < it->second.multiples.size(); ++i) {
  //     printf("%llu ", it->second.multiples[i]->first);
  //   }
  //   printf("\n");
  //   printf(" ** Final Probability = %llu / %llu", probability[it->second.factor_index].first, probability[it->second.factor_index].second);
  //   printf("\n\n");
  // }
}

ullong mod_inv(ullong x, ullong n, ullong mod) {
  if (x == 1)
    return 1;
  if (x == 0)
    return 0;
  if (n == 0)
    return 1;
  if (n == 1)
    return x % mod;

  ullong temp = mod_inv(x, n/2, mod) % mod;
  temp = ((temp % mod) * (temp % mod)) % mod;

  if (n & 1) {
    temp = ((temp % mod) * (x % mod)) % mod;
  }

  return temp;
}

void compute_div_invs() {
  size_t i;
  for (i=0; i<factors.size(); ++i) {
    factors[i]->divisors_inv = mod_inv(factors[i]->divisors, M-2, M);
  }
}

Number* create_new_number() {
  return &NumberPool[NumberPoolIndex++];
}
