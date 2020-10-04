#include <iostream>
#include <stack>
#include <vector>
#include <queue>

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

int meatiest(int n);
int leftout3(queue<int> &mq, vector<int> &st);
int leftout4(queue<int> &mq, vector<int> &st);
void swap(int &a, int &b);
void printq(int a, int b, int c, int d, int e);

int main(){
  std::ios::sync_with_stdio(false);

  int t, n;

  cin >> t;

  while(t--){
    cin >> n;
    int m = meatiest(n);
    cout << "! " << m << endl << std::flush;
  }

  return 0;
}

int meatiest(int n){
  queue<int> myque;
  int i;
  FORE(i, 1, n, 1){
    myque.push(i);
  }

  vector<int> st;
  int a, b, c, d, e;
  int p, q;

  while(myque.size() > 4){
    a = myque.front();
    myque.pop();
    b = myque.front();
    myque.pop();
    c = myque.front();
    myque.pop();
    d = myque.front();
    myque.pop();
    e = myque.front();
    myque.pop();

    // cout << "? " << a << " " << b << " " << c << " " << d << " " << e << endl << std::flush;
    printq(a, b, c, d, e);
    cin >> p >> q;

    if(st.size() == 2){
      st.pb(p);
    }
    if(st.size() == 0){
      st.pb(p);
      st.pb(q);
    }

    if((a!=p) && (a!=q)){
      myque.push(a);
    }
    if((b!=p) && (b!=q)){
      myque.push(b);
    }
    if((c!=p) && (c!=q)){
      myque.push(c);
    }
    if((d!=p) && (d!=q)){
      myque.push(d);
    }
    if((e!=p) && (e!=q)){
      myque.push(e);
    }
  }

  if(myque.size() == 3){
    return leftout3(myque, st);
  }
  else{
    return leftout4(myque, st);
  }
}

int leftout3(queue<int> &mq, vector<int> &st){
  int a, b, c, x, y, z, p, q;

  a = mq.front();
  mq.pop();
  b = mq.front();
  mq.pop();
  c = mq.front();
  mq.pop();

  x = st[0];
  y = st[1];
  z = st[2];

  // cout << "? " << a << " " << b << " " << c << " " << y << " " << z << endl << std::flush;
  printq(a, b, c, y, z);
  cin >> p >> q;

  if(p != y){
    // if meat(y) > meat(z)
    swap(y, z);
    // cout << "? " << a << " " << b << " " << c << " " << x << " " << y << endl << std::flush;
    printq(a, b, c, x, y);
    cin >> p >> q;

    if(p == y){
      // if meat(y) < meat(x)
      swap(x, y);
    }
  }

  // now meat(x) < meat(y) < meat(z)
  // cout << "? " << b << " " << c << " " << x << " " << y << " " << z << endl << std::flush;
  printq(b, c, x, y, z);
  cin >> p >> q;

  if(p == x)
    return a;

  // cout << "? " << a << " " << c << " " << x << " " << y << " " << z << endl << std::flush;
  printq(a, c, x, y, z);
  cin >> p >> q;

  if(p == x)
    return b;

  // cout << "? " << a << " " << b << " " << x << " " << y << " " << z << endl << std::flush;
  // cin >> p >> q;

  // if(p == x)
  //   return c;
  return c;
}

int leftout4(queue<int> &mq, vector<int> &st){
  vector<int> arr(4, 0);
  int a, b, c, x, y, z, p, q, t;

  arr[0] = mq.front();
  mq.pop();
  arr[1] = mq.front();
  mq.pop();
  arr[2] = mq.front();
  mq.pop();
  arr[3] = mq.front();
  mq.pop();

  x = st[0];
  y = st[1];

  int i = 0;
  while(true){
    a = arr[i];
    b = arr[(i+1)%4];
    c = arr[(i+2)%4];
    i = (i+3)%4;

    // cout << "? " << a << " " << b << " " << c << " " << x << " " << y << endl << std::flush;
    printq(a, b, c, x, y);
    cin >> p >> q;

    if((p!=x) && (q!=y))
      break;
  }

  bool yz = false;
  bool xy = false;
  if(p == x){
    // i.e., q != y => meat(x) < meat(q) and meat(x) < meat(y)
    z = q;
    t = q;
    yz = true;
  }
  else if(q == y){
    // i.e., p != x => meat(p) < meat(y) and meat(x) < meat(y)
    z = y;
    y = p;
    t = p;
    xy = true;
  }
  else if(p == y){
    z = q;
    t = q;
  }
  else if(q == x){
    z = y;
    y = x;
    x = p;
    t = p;
  }

  if(t == arr[0]){
    a = arr[1];
    b = arr[2];
    c = arr[3];
  }
  else if(t == arr[1]){
      a = arr[0];
      b = arr[2];
      c = arr[3];
    }
  else if(t == arr[2]){
      a = arr[0];
      b = arr[1];
      c = arr[3];
    }
  else{
    a = arr[0];
    b = arr[1];
    c = arr[2];
  }

  if(yz == true){
    // cout << "? " << a << " " << b << " " << c << " " << y << " " << z << endl << std::flush;
    printq(a, b, c, y, z);
    cin >> p >> q;

    if(p == z)
      swap(y, z);
  }

  if(xy == true){
    // cout << "? " << a << " " << b << " " << c << " " << x << " " << y << endl << std::flush;
    printq(a, b, c, x, y);
    cin >> p >> q;

    if(p == y)
      swap(x, y);
  }

  // now meat(x) < meat(y) < meat(z)
  // cout << "? " << b << " " << c << " " << x << " " << y << " " << z << endl << std::flush;
  printq(b, c, x, y, z);
  cin >> p >> q;

  if(p == x)
    return a;

  // cout << "? " << a << " " << c << " " << x << " " << y << " " << z << endl << std::flush;
  printq(a, c, x, y, z);
  cin >> p >> q;

  if(p == x)
    return b;

  return c;
}

void swap(int &a, int &b){
  int c;
  c = a;
  a = b;
  b = c;
}

void printq(int a, int b, int c, int d, int e){
  cout << "? " << a << " " << b << " " << c << " " << d << " " << e << endl << std::flush;
}
