class Solution {
using u8 = unsigned char;

    static constexpr int ALPHABET = 7;
    static constexpr int MAX_STATE = 117649; // 7^6

    // pattern[a*6 + b] -> bitmask of possible top blocks
    array<u8, 36> pattern{};

    // BAD[len][state] = this row configuration cannot form a pyramid
    array<bitset<MAX_STATE>, ALPHABET> badMemo;

    // Encode a row as base-7 number
    static unsigned encode(const string& s) {
        unsigned value = 0;
        for (char c : s)
            value = value * ALPHABET + (c - 'A');
        return value;
    }

    void buildPattern(const vector<string>& allowed) {
        for (const auto& s : allowed) {
            int key = (s[0] - 'A') * 6 + (s[1] - 'A');
            pattern[key] |= 1 << (s[2] - 'A');
        }
    }

    bool dfs(const string& cur, string& next, int pos, int size) {
        // Finished building the next row
        if (pos == size - 1) {
            if (size == 2) return true;

            unsigned state = encode(next);
            if (badMemo[size - 1][state]) return false;

            string upper(size - 1, 'G');
            if (!dfs(next, upper, 0, size - 1)) {
                badMemo[size - 1][state] = true;
                return false;
            }
            return true;
        }

        int key = (cur[pos] - 'A') * 6 + (cur[pos + 1] - 'A');
        u8 mask = pattern[key];

        while (mask) {
            unsigned bit = mask & -mask;
            mask -= bit;

            int c = countr_zero(bit);
            next[pos] = char('A' + c);

            if (dfs(cur, next, pos + 1, size))
                return true;
        }
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        pattern.fill(0);
        for (auto& b : badMemo) b.reset();

        buildPattern(allowed);

        string next(bottom.size() - 1, 'G');
        return dfs(bottom, next, 0, bottom.size());
    }
};