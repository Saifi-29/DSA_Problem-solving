class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, int> right;
        unordered_map<int, int> left;

        for(int i=0;i<nums.size();i++)
        {
            right[nums[i]]++;
        }
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            int mid = nums[i];
            right[mid]--;
            int l = left[mid*2];
            int r = right[mid*2];

            res = (res%MOD+(l%MOD*r%MOD));
            left[mid]++;
        }
        return res;
    }
};