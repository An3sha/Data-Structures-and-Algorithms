//we can use two pointers approach if the array is sorted in O(N) time
// if the array is not sorted then time complexity will increase O(NlogN)+O(N)

//O(N^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if((nums[i]+nums[j])==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
            
        }
        return ans;
    }
};

//O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            int x = target - nums[i];
            if(mpp.find(x)!=mpp.end())
            {
                ans.push_back(mpp[x]);
                ans.push_back(i);
            }
            mpp[nums[i]]=i;
        }
        return ans;   
    }
};
