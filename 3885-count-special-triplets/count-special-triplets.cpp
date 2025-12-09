class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        unordered_map<int, long long> rightCount;
        unordered_map<int, long long> leftCount;

        // fill rightCount with full array
        for (int x : nums) rightCount[x]++;

        long long result = 0;

        for (int j = 0; j < n; j++) {
            int mid = nums[j];
            rightCount[mid]--;  // j moves from right to left

            long long left = leftCount[mid * 2];
            long long right = rightCount[mid * 2];

            result = (result + left * right) % MOD;

            leftCount[mid]++;
        }

        return result % MOD;
    }
};