class Solution {
public:
    vector<int> solve(int a)
    {
        vector<int> dummy;
        long long int ans = 1;
        dummy.push_back(1);
        for(int i=1;i<a;i++)
        {
            ans = ans * (a-i);
        ans = ans/(i);
        dummy.push_back(ans);

        }
        return dummy;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // vector<int> dummy;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(solve(i));
        }
        return ans;
    }
};