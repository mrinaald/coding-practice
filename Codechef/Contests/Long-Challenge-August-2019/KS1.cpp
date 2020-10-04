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

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_N 100000
#define MAX_BITS 20
#define ROOT_NODE 0


// vector<vector<int>> vectorTable(MAX_N+5, vector<int>());
// int vectorTableCounter;

struct TrieNode{
  int child[2];
  // int vectorTableIndex = -1;
  int count;
  llong offset = 0;
};
TrieNode nodePool[(MAX_BITS+1)*MAX_N];
int nodePoolCounter;

vector<int> mask(MAX_BITS+2);

ullong insert(const int prefix_xor, const int index);

int main(){
  // std::ios::sync_with_stdio(false);

  int t, n;
  int prefix_xor;
  int i, a;
  ullong count;

  for (i=MAX_BITS; i>=0; --i)
    mask[i] = 1<<i;

  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);

    prefix_xor = 0;
    count = 0;
    // vectorTableCounter = 0;
    nodePoolCounter = 1;
    nodePool[ROOT_NODE].child[0] = 0;
    nodePool[ROOT_NODE].child[1] = 0;
    // nodePool[ROOT_NODE].vectorTableIndex = -1;
    nodePool[ROOT_NODE].count = 0;
    nodePool[ROOT_NODE].offset = 0;

    for (i=0; i<n; ++i){
      scanf("%d", &a);

      prefix_xor = prefix_xor ^ a;

      if (!prefix_xor){
        count += i;
      }
      count += insert(prefix_xor, i);
    }

    printf("%llu\n", count);
  }

  return 0;
}

ullong insert(const int prefix_xor, const int index){
  int node = ROOT_NODE;
  bool value;
  int i;

  for (int i=MAX_BITS; i>=0; --i){
    value = prefix_xor & mask[i];

    if (!nodePool[node].child[value]){
      nodePool[node].child[value] = nodePoolCounter;
      nodePool[nodePoolCounter].child[0] = 0;
      nodePool[nodePoolCounter].child[1] = 0;
      // nodePool[nodePoolCounter].vectorTableIndex = -1;
      nodePool[nodePoolCounter].count = 0;
      nodePool[nodePoolCounter].offset = 0;
      nodePoolCounter++;
    }

    node = nodePool[node].child[value];
  }

  // if (nodePool[node].vectorTableIndex == -1){
  //   nodePool[node].vectorTableIndex = vectorTableCounter;
  //   vectorTable[vectorTableCounter].clear();
  //   vectorTable[vectorTableCounter].push_back(index);
  //   vectorTableCounter++;
  //   return 0;
  // }

  // int id = nodePool[node].vectorTableIndex;
  // ullong count = 0;
  // for (i=0; i < vectorTable[id].size(); ++i){
  //   count += (index - vectorTable[id][i] - 1);
  // }

  // vectorTable[id].push_back(index);

  if (nodePool[node].count == 0){
    nodePool[node].count = 1;
    nodePool[node].offset = index + 1;
    return 0;
  }

  ullong count = 0;
  count = nodePool[node].count;
  count *= index;
  count = count - nodePool[node].offset;

  nodePool[node].count += 1;
  nodePool[node].offset += index + 1;

  return count;
}
