/******************************************************************
*** 56 ms, 34.7 MB
******************************************************************/
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> hashTable({
            {1, "I"},
            {5, "V"},
            {10, "X"},
            {50, "L"},
            {100, "C"},
            {500, "D"},
            {1000, "M"}
        });

        string ret = "";
        int pos = 1;
        int tempPos;
        int digit;

        while (num > 0){
            digit = num%10;

            switch(digit){
                case 1:
                    ret = hashTable[pos] + ret; break;

                case 2:
                    ret = hashTable[pos] + hashTable[pos] + ret; break;

                case 3:
                    ret = hashTable[pos] + hashTable[pos] + hashTable[pos] + ret; break;

                case 4:
                    tempPos = pos*5; ret = hashTable[pos] + hashTable[tempPos] + ret; break;

                case 5:
                    tempPos = pos*5; ret = hashTable[tempPos] + ret; break;

                case 6 :
                    tempPos = pos*5; ret = hashTable[tempPos] + hashTable[pos] + ret; break;

                case 7:
                    tempPos = pos*5; ret = hashTable[tempPos] + hashTable[pos] + hashTable[pos] + ret; break;

                case 8:
                    tempPos = pos*5; ret = hashTable[tempPos] + hashTable[pos] + hashTable[pos] + hashTable[pos] + ret; break;

                case 9:
                    tempPos = pos*10; ret = hashTable[pos] + hashTable[tempPos] + ret; break;
            }

            num /= 10;
            pos *= 10;
        }

        return ret;
    }
};


/******************************************************************
 *** 4 ms, 83 MB
 ******************************************************************/
class Solution {
public:
    string intToRoman(int num) {
        string roman = "";

        while (num){
            if (num >= 1000){
                num -= 1000;
                roman.append("M");
            }
            else if (num >= 900){
                num -= 900;
                roman.append("CM");
            }
            else if (num >= 500){
                num -= 500;
                roman.append("D");
            }
            else if (num >= 400){
                num -= 400;
                roman.append("CD");
            }
            else if (num >= 100){
                num -= 100;
                roman.append("C");
            }
            else if (num >= 90){
                num -= 90;
                roman.append("XC");
            }
            else if (num >= 50){
                num -= 50;
                roman.append("L");
            }
            else if (num >= 40){
                num -= 40;
                roman.append("XL");
            }
            else if (num >= 10){
                num -= 10;
                roman.append("X");
            }
            else{
                switch(num){
                    case 9:
                        num -= 9; roman.append("IX"); break;
                    case 8:
                        num -= 8; roman.append("VIII"); break;
                    case 7:
                        num -= 7; roman.append("VII"); break;
                    case 6:
                        num -= 6; roman.append("VI"); break;
                    case 5:
                        num -= 5; roman.append("V"); break;
                    case 4:
                        num -= 4; roman.append("IV"); break;
                    case 3:
                        num -= 3; roman.append("III"); break;
                    case 2:
                        num -= 2; roman.append("II"); break;
                    case 1:
                        num -= 1; roman.append("I"); break;
                }
            }
        }

        return roman;
    }
};
