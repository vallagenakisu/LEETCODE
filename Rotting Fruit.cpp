#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dis(n, vector<int>(m, 0));
    int fresh = 0;

    // Enqueue all rotten oranges and count fresh ones
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) q.push({i, j});
            if (grid[i][j] == 1) fresh++;
        }
    }

    int ans = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                dis[nx][ny] = dis[x][y] + 1;
                ans = max(ans, dis[nx][ny]);
                q.push({nx, ny});
                fresh--;
            }
        }
    }

    return fresh == 0 ? ans : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << orangesRotting(grid);
}