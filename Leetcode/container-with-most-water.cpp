/******************************************************************
*** 16 ms
******************************************************************/
class Solution {
public:
  int maxArea(vector<int>& height) {
    if (height.size() == 2){
      return min(height[0], height[1]);
    }

    int left = 0;
    int right = height.size()-1;

    int h, max_water = 0;

    while (left < right){
      h = min(height[left], height[right]);

      if ((right-left)*h > max_water)
        max_water = (right-left)*h;

      if (h == height[left])
        left++;
      else
        right--;
    }

    return max_water;
  }
};


/******************************************************************
 *** 20 ms
 ******************************************************************/
class Solution {
public:
  int maxArea(vector<int>& height) {
    int numLines = height.size();

    if (numLines == 2)
      return min(height[0], height[1]);

    int ret = 0;
    int l = 0;
    int r = numLines-1;

    while(l < r){
      ret = max(ret, (r-l)*min(height[l], height[r]));

      if (height[l] < height[r])
        l++;
      else
        r--;
    }

    return ret;
  }
};
