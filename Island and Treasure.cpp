#include<bits/stdc++.h>
using namespace std;
void bfs(int i , int j , vector<vector<int>> &grid, vector<vector<int>> &vis , vector<vector<int>> &dis)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    q.push({i,j});
    vis[i][j] = 1;
    dis[i][j] = 0;
    while(!q.empty())
    {
        auto [a,b] = q.front();
        q.pop();
        for(int k = 0 ; k < 4 ; k++)
        {
            int nx = a + dx[k];
            int ny = b + dy[k];
            if(nx >= 0 and nx < n and ny >= 0 and ny < m )
            {
                if(!vis[nx][ny])
                {
                    if(grid[nx][ny] == 2147483647)
                    {
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                        dis[nx][ny] = min(1 + dis[a][b],dis[nx][ny]);
                        // dis[nx][ny] = 1 + dis[a][b];

                    }
                    else if(grid[nx][ny] == -1)
                    {
                        dis[nx][ny] = -1;
                    }
                }
            }
        }

    }
}
void islandsAndTreasure(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dis(n,(vector<int>(m,2147483647)));
    // for(auto x : dis)
    // {
    //     for(auto y : x)
    //     cout << y << " ";
    //     cout << endl;
    // }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            vector<vector<int>> vis(n,(vector<int>(m,0)));
            if(grid[i][j] == 0)
            {
                bfs(i,j,grid,vis,dis);
            }
        }
    }
    grid = dis;
    for(auto x : grid)
    {
        for(auto y : x)
        cout << y << " ";
        cout << endl;
    }       
}

int main()
{
//    vector<vector<int>> grid = {
//     {2147483647, -1, 0, 2147483647},
//     {2147483647, 2147483647, 2147483647, -1},
//     {2147483647, -1, 2147483647, -1},
//     {0, -1, 2147483647, 2147483647}
//     };
    vector<vector<int>> grid = {
        {0,-1},
        {2147483647,2147483647}
    };
    islandsAndTreasure(grid);
}