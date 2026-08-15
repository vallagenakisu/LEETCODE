#include<bits/stdc++.h>
using namespace std;
void dfs(int i , int j , vector<vector<int>> &grid , vector<vector<int>> &vis,int &count)
{
    vis[i][j] = 1;   
    count++; 
    int n = grid.size();
    int m = grid[0].size();
    int dx[] ={1,-1,0,0};
    int dy[] ={0,0,1,-1};
    for(int k = 0 ; k < 4; k++)
    {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx >= 0 and nx < n and ny >= 0 and ny < m)
        {
            if(!vis[nx][ny] and grid[nx][ny] == 1)
            {
                dfs(nx,ny,grid,vis,count);
            }
        }
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0)); 
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
       
        for(int j = 0 ; j < m ; j++)
        {
            int count = 0 ;
            if(!vis[i][j] and grid[i][j] == 1)
            dfs(i,j,grid,vis,count);
            ans = max(count ,ans );
        }
   
    }
    return ans;        
}
int main()
{
    vector<vector<int>> grid = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 0, 1}
};
    cout << maxAreaOfIsland(grid);

}