/******************************************************************
*** 16 ms, O(1) memory
******************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;

        int low, high;
        int len = s.length();
        int startIndex = 0;
        int maxLength = 1;
        int temp;

        for(int i=1; i<len; ++i){
            // even length substring with (i-1) and i as center
            low = i-1;
            high = i;
            while(low>=0 && high<len && s[low]==s[high]){
                temp = high-low+1;
                if (temp > maxLength){
                    maxLength = temp;
                    startIndex = low;
                }
                low--;
                high++;
            }


            // odd length substring with i as center
            low = i-1;
            high = i+1;
            while(low>=0 && high<len && s[low]==s[high]){
                temp = high-low+1;
                if (temp > maxLength){
                    maxLength = temp;
                    startIndex = low;
                }
                low--;
                high++;
            }
        }

        return s.substr(startIndex, maxLength);
    }
};

/******************************************************************
*** 192 ms
******************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        if (s.length() == 2){
            if (s[0] == s[1])
                return s;
            else
                return s.substr(1);
        }

        int len = s.length();
        vector<vector<bool>> isPalin(len, vector<bool>(len, false));
        int maxLength = 1;
        int startIndex;
        int i, j, l;

        // setting up table for 1 length substring
        for(i=0; i<len; ++i){
            isPalin[i][i] = true;
            startIndex = i;
        }

        // setting up table for 2 length substring
        for(i=0; i<len-1; ++i){
            if (s[i] == s[i+1]){
                isPalin[i][i+1] = true;
                maxLength = 2;
                startIndex = i;
            }
        }

        // going bottom-up to compute answer
        for(l=3; l<=len; ++l){
            for(i=0; i<=(len-l); ++i){
                j = i+l-1;

                if (s[i]==s[j] && isPalin[i+1][j-1]==true){
                    isPalin[i][j] = true;
                    startIndex = i;
                    maxLength = l;
                }
            }
        }

        // cout << startIndex << ' ' << maxLength << endl;
        return s.substr(startIndex, maxLength);
    }
};


/******************************************************************
*** 216 ms
******************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;

        int len = s.length();
        vector<vector<bool>> isPalin(len, vector<bool>(len, false));

        int i, j;
        for(i=0; i<len; ++i){
            isPalin[i][i] = true;
        }

        int startIndex = 0;
        int maxLength = 1;
        for(i=0; i<len-1; ++i){
            if (s[i] == s[i+1]){
                isPalin[i][i+1] = true;
                if (2 > maxLength){
                    startIndex = i;
                    maxLength = 2;
                }
            }
        }

        for(int l=3; l<=len; ++l){
            for(i=0; i<=(len-l); ++i){
                j = i+l-1;

                if (isPalin[i+1][j-1] && s[i]==s[j]){
                    isPalin[i][j] = true;
                    if (l > maxLength){
                        startIndex = i;
                        maxLength = l;
                    }
                }
            }
        }

        return s.substr(startIndex, maxLength);
    }
};
