/******************************************************************
*** 12 ms
******************************************************************/
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1)
      return s;

    if (s.length() <= numRows)
      return s;

    string retStr = "";
    int len = s.length();
    int i, j;
    int diff1 = (numRows-1)<<1;
    int diff2 = 0;

    for (i=0; i<numRows; ++i){
      j = i;
      retStr += s[j];
      while(j < len){
        if (diff1){
          j += diff1;
          if (j < len)
            retStr += s[j];
        }
        if (diff2){
          j += diff2;
          if (j < len)
            retStr += s[j];
        }
      }

      diff1 -= 2;
      diff2 += 2;
    }

    return retStr;
  }
};


/******************************************************************
*** 28 ms
******************************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }

        if (s.length() <= numRows){
            return s;
        }

        /****** Given solution ******/
        bool goingDown = true;
        int curRow = 0;

        vector<string> pattern(numRows);

        int len = s.length();
        int i;
        for (i=0; i<len; ++i){
            pattern[curRow] += s[i];
            if (curRow == 0){
                goingDown = true;
            }
            if (curRow == numRows-1){
                goingDown = false;
            }

            if (goingDown == true){
                curRow++;
            }
            else{
                curRow--;
            }
        }

        string ans = "";
        for(string row : pattern){
            ans += row;
        }

        return ans;
    }
};


/******************************************************************
*** 260 ms
******************************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1){
            return s;
        }

        if (s.length() <= numRows){
            return s;
        }

        int len = s.length();
        // will store the transpose of the pattern;
        int r = 0;
        int row_count = 0;
        int temp = (2*numRows) - 2;
        while (r < len){
            row_count++;
            if (r%temp == 0){
                r += numRows;
            }
            else{
                r++;
            }
        }

        vector<vector<string> > pattern(row_count, vector<string>(numRows, ""));
        bool forward = true;
        int i, j=0;
        r = 0;
        for(i=0; i<len; ++i){
            if (j == 0){
                pattern[r][j] = s.substr(i, 1);
                j++;
                forward = true;
            }
            else if (j == numRows-1){
                pattern[r][j] = s.substr(i, 1);
                j--;
                r++;
                forward = false;
            }
            else if (forward == true){
                pattern[r][j] = s.substr(i, 1);
                j++;
            }
            else if (forward == false){
                pattern[r][j] = s.substr(i, 1);
                j--;
                r++;
            }
        }

        string ans = "";

        for(i=0; i<numRows; ++i){
            for(r=0; r<row_count; ++r){
                if (pattern[r][i] == "")
                    continue;
                ans += pattern[r][i];
            }
        }

        return ans;
    }
};
