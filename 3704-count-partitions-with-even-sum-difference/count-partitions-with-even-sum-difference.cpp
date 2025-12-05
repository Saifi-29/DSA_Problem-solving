class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int odd = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2 != 0)
            odd++;
        }
        if(odd%2==0)
        return nums.size()-1;
        else return 0;
    }
};