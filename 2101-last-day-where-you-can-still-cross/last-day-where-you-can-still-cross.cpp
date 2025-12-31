class DSU {
    vector<int> parent, sz;

public:
    explicit DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (sz[x] > sz[y])
            swap(x, y);

        parent[x] = y;
        sz[y] += sz[x];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        const int LEFT = 0;
        const int RIGHT = row * col + 1;

        DSU dsu(row * col + 2);
        vector<vector<int>> grid(row, vector<int>(col, 0));

        const int dirs[8][2] = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        for (int day = 0; day < row * col; ++day) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            grid[r][c] = 1;

            int id = r * col + c + 1;

            for (const auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc]) {
                    int nid = nr * col + nc + 1;
                    dsu.unite(id, nid);
                }
            }

            if (c == 0)
                dsu.unite(LEFT, id);
            if (c == col - 1)
                dsu.unite(RIGHT, id);

            if (dsu.find(LEFT) == dsu.find(RIGHT))
                return day;
        }

        return -1;
    }
};