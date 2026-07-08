class Solution {
public:
static const int MOD = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos, digit;
        vector<long long> prefSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            prefSum[i + 1] = prefSum[i] + d;
            if (d != 0) {
                pos.push_back(i);
                digit.push_back(d);
            }
        }

        int m = digit.size();
        vector<long long> pw(m + 1, 1), prefHash(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pw[i + 1] = (pw[i] * 10) % MOD;
            prefHash[i + 1] = (prefHash[i] * 10 + digit[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = (prefSum[r + 1] - prefSum[l]) % MOD;

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            long long x = 0;

            if (L <= R) {
                int len = R - L + 1;
                x = (prefHash[R + 1] - prefHash[L] * pw[len]) % MOD;
                if (x < 0) x += MOD;
            }

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};