#include<bits/stdc++.h>
using namespace std;

// 1 1 1 1 0
// 1 1 0 1 0
// 1 1 0 0 0 
// 0 0 0 0 0 
const int N = 309;
int vis[N][N];
void dfs(int i, int j, vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vis[i][j] = 1;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            if (!vis[ni][nj] && grid[ni][nj] == '1') {
                dfs(ni, nj, grid);
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid)
{
    int components = 0 ;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                dfs(i, j, grid);
                ++components;
            }
        }
    }
    return components;
}
int main()
{
    vector<vector<char>> grid = {
        {'0','1','1','1','0'},
        {'0','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << numIslands(grid);
}