class Solution {
public:
    int numOfWays(int n) {
         const long long MOD = 1e9 + 7;

        long long a = 6; // patterns with 2 colors
        long long b = 6; // patterns with 3 colors

        for (int i = 2; i <= n; i++) {
            long long newA = (3 * a + 2 * b) % MOD;
            long long newB = (2 * a + 2 * b) % MOD;
            a = newA;
            b = newB;
        }

        return (a + b) % MOD;
    }
};