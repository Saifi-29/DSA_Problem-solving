class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        vector<int> parent(n), rank(n, 0);
        vector<bool> know(n, false);

        know[0] = true;
        know[firstPerson] = true;

        // Union-Find helpers
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                if (rank[x] < rank[y]) parent[x] = y;
                else if (rank[x] > rank[y]) parent[y] = x;
                else {
                    parent[y] = x;
                    rank[x]++;
                }
            }
        };

        // Initially everyone is their own parent
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> involved;

            int j = i;
            // Union all meetings at the same time
            while (j < meetings.size() && meetings[j][2] == time) {
                unite(meetings[j][0], meetings[j][1]);
                involved.push_back(meetings[j][0]);
                involved.push_back(meetings[j][1]);
                j++;
            }

            // Mark components that have the secret
            unordered_set<int> good;
            for (int p : involved) {
                if (know[p]) {
                    good.insert(find(p));
                }
            }

            // Spread secret only within valid components
            for (int p : involved) {
                if (good.count(find(p)))
                    know[p] = true;
                else
                    parent[p] = p;  // reset ONLY uninformed people
            }

            i = j;
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (know[i]) result.push_back(i);

        return result;
    }
};