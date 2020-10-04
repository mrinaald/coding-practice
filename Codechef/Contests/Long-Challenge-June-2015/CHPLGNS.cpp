#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct Vertex{
  int x;
  int polyID;

  Vertex(){
    x = 0;
    polyID = -1;
  }

  Vertex(int _x, int _polyID){
    x = _x;
    polyID = _polyID;
  }
};

bool myComparator(const Vertex &lhs, const Vertex &rhs){
  return lhs.x < rhs.x;
}

int main(){
  std::ios::sync_with_stdio(false);

  int t, n, m;
  int _n;
  int min_x;
  int i;
  int x, y;

  cin >> t;

  while(t--){
    cin >> n;

    vector<Vertex> polygon(n);

    for(_n = 0; _n<n; ++_n){
      cin >> m;

      cin >> x;
      cin >> y;
      min_x = x;

      for(i=1; i<m; ++i){
        cin >> x;
        cin >> y;

        min_x = (min_x < x)?min_x:x;
      }

      polygon[_n] = Vertex(min_x, _n);
    }

    sort(rall(polygon), myComparator);

    vector<int> answer(n);
    for(i=0; i<n; ++i){
      answer[polygon[i].polyID] = i;
    }

    for(i=0; i<n; ++i){
      cout << answer[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
