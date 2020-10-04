/******************************************************************
*** 8ms, 9.7 MB
******************************************************************/
class Solution {
public:
  string longestCommonPrefix(const string& str1, const string& str2){
    int len1 = str1.length();
    int len2 = str2.length();
    string prefix = "";

    int len = (len1 > len2)?len2:len1;
    for(int i=0; i<len; ++i){
      if (str1[i] == str2[i]){
        prefix += str1[i];
      }
      else
        break;
    }

    return prefix;
  }

  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() <= 0)
      return "";

    int n = strs.size();
    string prefix = strs[0];

    for(int i=1; i<n; ++i){
      prefix = longestCommonPrefix(prefix, strs[i]);
      if (prefix == "")
        break;
    }

    return prefix;
  }
};


/******************************************************************
 *** 8 ms, 8.9 MB
 ******************************************************************/
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix = "";

    if (strs.size() == 0)
      return prefix;
    else if (strs.size() == 1)
      return strs[0];

    prefix = strs[0];
    int n = strs.size();
    int i;
    int j;

    for (i=1; i<n; ++i){
      for (j=0; j<prefix.length() && j<strs[i].size(); ++j){
        if (prefix[j] != strs[i][j])
          break;
      }

      if (j == 0){
        prefix = "";
        break;
      }
      else if (j < prefix.length()){
        prefix = prefix.substr(0, j);
      }
    }

    return prefix;
  }
};
