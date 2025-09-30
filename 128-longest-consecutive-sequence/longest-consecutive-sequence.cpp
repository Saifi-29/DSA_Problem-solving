class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> arr(s.begin(), s.end());
        if(nums.size() == 0) return 0;

        int count = 1, maxlen = 0;

        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] - arr[i-1] == 1)
            count++;
            else{
                maxlen = max(maxlen, count);
                count = 1;
            }
        }
        maxlen = max(maxlen, count);
        return maxlen;
    }
};