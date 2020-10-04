/*************************************************************
 *** 32 ms
 *************************************************************/
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1)
      return s.length();

    int len = s.length();
    int ret = 1;
    map<char, int> hashMap;
    int l, r;
    char ch;

    l = 0;
    hashMap[s[0]] = 0;

    for(r=1; r<len; ++r){
      ch = s[r];
      if (hashMap.find(ch) != hashMap.end()){
        l = max(hashMap[ch]+1, l);
      }

      ret = max(ret, r-l+1);
      hashMap[ch] = r;
    }

    return ret;
  }
};


/*************************************************************
 *** 16 ms
 *************************************************************/
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1)
      return s.length();

    map<char, int> hashMap;
    int length = s.length();
    int max_len = 1;
    int start = 0;

    for(int i=0; i<length; ++i){
      if (hashMap.find(s[i]) == hashMap.end()){
        hashMap[s[i]] = i;
      }
      else{
        max_len = max(max_len, i-start);
        start = max(hashMap[s[i]]+1, start);
        hashMap[s[i]] = i;
      }
    }

    max_len = max(max_len, length-start);


    return max_len;
  }
};
