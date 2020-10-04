#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

#define NUM_ROOKS 666
#define MAX_TURNS 2000
#define CENTER 500

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

std::pair<int, int> king;
vector< std::pair<int, int> > rook(NUM_ROOKS);
bool reached_center = false;

/* Corner:
   0 -> (1, 1)
   1 -> (1, 999)
   2 -> (999, 1)
   3 -> (999, 999)
 */
int corner = -1;

void move_king();

int main(){
  // std::ios::sync_with_stdio(false);

  int i;
  int x, y;

  scanf("%d %d", &x, &y);
  king.first = x;
  king.second = y;

  for (i=0; i<NUM_ROOKS; ++i) {
    scanf("%d %d", &x, &y);
    rook[i].first = x;
    rook[i].second = y;
  }

  int turns = MAX_TURNS;
  while (turns--) {
    // compute best king move possible
    move_king();

    // maka a move
    printf("%d %d\n", king.first, king.second);
    fflush(stdout);

    // read from stdin
    scanf("%d %d %d", &i, &x, &y);

    if ( i==-1 && x==-1 && y==-1 )
      break;    // king got checked, we won

    if ( i==0 && x==0 && y==0 )
      break;    // made some invalid query, quit

    i--;    // Using 0-index
    // update rook's position
    rook[i].first = x;
    rook[i].second = y;
  }

  return 0;
}

void move_king() {
  // check whether next move can get us checked
  for (int i=0; i<NUM_ROOKS; ++i) {
    if ( rook[i].first == king.first-1 ) {
      king.first--;
      return;
    }
    if ( rook[i].first == king.first+1 ) {
      king.first++;
      return;
    }
    if ( rook[i].second == king.second-1 ) {
      king.second--;
      return;
    }
    if ( rook[i].second == king.second+1 ) {
      king.second++;
      return;
    }
  }

  if ( !reached_center ) {
    if ( (king.first == CENTER) && (king.second == CENTER) ) {
      reached_center = true;
      // start moving towards one corner
      int ll = 0;   // rook.row < CENTER and rook.col < CENTER
      int lg = 0;   // rook.row < CENTER and rook.col > CENTER
      int gl = 0;
      int gg = 0;

      for (int i=0; i<NUM_ROOKS; ++i) {
        if ( (rook[i].first < CENTER) && (rook[i].second < CENTER) ) {
          ll++;
        }
        else if ( (rook[i].first < CENTER) && (rook[i].second > CENTER) ) {
          lg++;
        }
        else if ( (rook[i].first > CENTER) && (rook[i].second < CENTER) ) {
          gl++;
        }
        else {
          gg++;
        }
      }

      int minimum = std::min(ll, std::min(lg, std::min(gl, gg)));

      // initialize corner with the opposite of the minimum
      if ( minimum == ll ) {
        corner = 3;
      }
      else if ( minimum == lg ) {
        corner = 2;
      }
      else if ( minimum == gl ) {
        corner = 1;
      }
      else {
        corner = 0;
      }

      switch(corner) {
      case 0: king.first--; king.second--; break;
      case 1: king.first--; king.second++; break;
      case 2: king.first++; king.second--; break;
      case 3: king.first++; king.second++; break;
      }
    }
    else if ( king.first == CENTER ) {
      if ( king.second > CENTER ) {
        king.second--;
      }
      else {
        king.second++;
      }
    }
    else if ( king.second == CENTER ) {
      if ( king.first > CENTER ) {
        king.first--;
      }
      else {
        king.first++;
      }
    }
    else {
      // have to move diagonally
      if ( (king.first > CENTER) && (king.second > CENTER) ) {
        king.first--;
        king.second--;
      }
      else if ( (king.first < CENTER) && (king.second < CENTER) ) {
        king.first++;
        king.second++;
      }
      else if ( (king.first < CENTER) && (king.second > CENTER) ) {
        king.first++;
        king.second--;
      }
      else {
        king.first--;
        king.second++;
      }
    }
  }
  else {
    switch(corner) {
    case 0: king.first--; king.second--; break;
    case 1: king.first--; king.second++; break;
    case 2: king.first++; king.second--; break;
    case 3: king.first++; king.second++; break;
    }
  }
}
