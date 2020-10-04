/******************************************************************
 *** 4 ms
 ******************************************************************/
class Solution {
public:
    int myAtoi(string str) {
        if(str.length() == 0)
            return 0;

        int len = str.length();
        int start = 0;

        while (start<len && str[start]==' ')
            start++;

        int ret = 0;
        bool negative = false;
        if (str[start] == '-'){
            negative = true;
            start++;
        }
        else if (str[start] == '+')
            start++;

        int ch;
        while(start<len && str[start]>='0' && str[start]<='9'){
            ch = str[start] - '0';

            if (ret > (INT_MAX-ch)/10){
                if (negative){
                    ret = INT_MIN;
                }
                else{
                    ret = INT_MAX;
                }
                break;
            }

            ret = (10*ret  + ch);
            start++;
        }

        if (negative && ret!=INT_MIN)
            return -ret;
        else
            return ret;
    }
};

/******************************************************************
*** 16 ms
******************************************************************/
class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int f=0;

        while ((f < len) && (str[f] == ' '))
            f++;

        if (f == len)
            return 0;

        bool negative = false;
        if (str[f] == '-'){
            negative = true;
            f++;
        }
        else if (str[f] == '+'){
            negative = false;
            f++;
        }
        if (f == len)
            return 0;

        if (str[f] < '0' || str[f] > '9')
            return 0;

        int ret = 0;
        bool overflow = false;

        while(f < len){
            if (str[f] < '0' || str[f] > '9')
                break;

            if (ret > INT_MAX/10){
                overflow = true;
                break;
            }
            else if (ret == INT_MAX/10 && (str[f]-'0') > 7){
                overflow = true;
                break;
            }

            ret = (ret*10) + (str[f]-'0');
            f++;
        }

        if (overflow == true){
            if (negative == true)
                return INT_MIN;
            else
                return INT_MAX;
        }

        if (negative == true)
            return -ret;
        else
            return ret;
    }
};
