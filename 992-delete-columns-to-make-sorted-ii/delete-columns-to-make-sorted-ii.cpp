class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        if (n <= 1) return 0;
        int m = strs[0].length();
        
        int deletions = 0;
        vector<bool> is_sorted(n - 1, false);

        for (int j = 0; j < m; ++j) {
            bool can_keep = true;
            for (int i = 0; i < n - 1; ++i) {
                if (!is_sorted[i] && strs[i][j] > strs[i+1][j]) {
                    can_keep = false;
                    break;
                }
            }

            if (can_keep) {
                for (int i = 0; i < n - 1; ++i) {
                    if (strs[i][j] < strs[i+1][j]) {
                        is_sorted[i] = true;
                    }
                }
            } else {
                deletions++;
            }
        }

        return deletions;
    }
};