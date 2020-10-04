/******************************************************************
 *** 108 ms, 15.7 MB
 ******************************************************************/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        int n = nums.size();
        if (n <= 2)
            return ret;

        sort(nums.begin(), nums.end());

        if (nums[0] > 0)
            return ret;

        int i, j, k;
        int x, s;

        i = 0;
        while (i < n){
            j = i+1;
            k = n-1;
            while (j < k){
                if (k == i){
                    k--;
                    continue;
                }

                s = nums[i] + nums[j] + nums[k];
                if (s == 0){
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];

                    ret.push_back(temp);

                    x = nums[j];
                    while (j<k && nums[j]==x)
                        j++;

                    x = nums[k];
                    while (j<k && nums[k]==x)
                        k--;
                }
                else if (s < 0){
                    x = nums[j];
                    while (j<k && nums[j]==x)
                        j++;
                }
                else{
                    x = nums[k];
                    while (j<k && nums[k]==x)
                        k--;
                }
            }

            x = nums[i];
            while (i<n && nums[i]==x)
                i++;
        }

        return ret;
    }
};


/******************************************************************
 *** 112 ms, 17.6 MB
 ******************************************************************/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        if (nums.size() <= 2)
            return ret;

        int size = nums.size();

        sort(nums.begin(), nums.end());

        int i;
        int l, r;
        int sum;

        for(i=0; i<size-1; ++i){
            l = i+1;
            r = size-1;

            while(l < r){
                sum = nums[i] + nums[l] + nums[r];

                if (sum == 0){
                    vector<int> triplet(3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[l];
                    triplet[2] = nums[r];

                    ret.push_back(triplet);

                    while(l < r && nums[l] == triplet[1])
                        l++;
                    while(r > l && nums[r] == triplet[2])
                        r--;
                }
                else if (sum < 0)
                    l++;
                else
                    r--;
            }

            while (i<size-1 && nums[i] == nums[i+1])
                i++;
        }

        return ret;
    }
};


/******************************************************************
 *** 820 ms, 126.5 MB
 ******************************************************************/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> uniqueTriplets;

        if (nums.size() <= 2)
            return ret;

        int size = nums.size();

        sort(nums.begin(), nums.end());

        int i;
        int l, r;
        int sum;

        for(i=0; i<size-1; ++i){
            l = i+1;
            r = size-1;

            while (l < r){
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0){
                    vector<int> triplet(3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[l];
                    triplet[2] = nums[r];

                    uniqueTriplets.insert(triplet);
                    l++;
                    r--;
                }
                else if(sum < 0)
                    l++;
                else
                    r--;
            }
        }

        for (auto v: uniqueTriplets){
            ret.push_back(v);
        }

        return ret;
    }
};
