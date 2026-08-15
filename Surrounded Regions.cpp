#include<bits/stdc++.h>
using namespace std;

bool dfs(int i , int j ,vector<vector<char>> &board ,vector<vector<int>> &vis , vector<pair<int,int>> &regions,int &flag)
{
    int m = board.size();
    int n = board[0].size();
    vis[i][j] = 1;
    regions.push_back({i,j});
    if(i == 0 or i == m-1 ) flag = 1;
    if(j == 0 or j == n-1 ) flag = 1;
    int dx[] ={1,-1,0,0};
    int dy[] ={0,0,1,-1};
    for(int k = 0 ; k < 4 ; k++)
    {
        int ni = i + dx[k]; 
        int nj = j + dy[k];
        if(ni >= 0 and ni < m and nj >= 0 and nj < n )
        {

            if(!vis[ni][nj] and board[ni][nj] != 'X')
            {
                dfs(ni,nj,board,vis,regions,flag);
            }
        }

    }
    // if flag = 1 means not surrounded 
    if(!flag) return false;
    else return true;
}


void solve(vector<vector<char>>& board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            vector<pair<int,int>> regions;
            int flag = 0;
            if(!vis[i][j] and board[i][j] !='X')
            {
                // not true means surrounded region 
                if(!dfs(i,j,board,vis,regions,flag))
                {
                    for(auto [a,b] : regions)
                    {
                        board[a][b] = 'X';
                    }
                }
            }
        }
    }       
}



int main()
{
vector<vector<char>> board = {
    {'O','X','X','O','X'},
    {'X','O','O','X','O'},
    {'X','O','X','O','X'},
    {'O','X','O','O','O'},
    {'X','X','O','X','O'}
};
    solve(board);
    for(auto x : board)
    {
        for(auto y : x)
        cout << y << " ";
        cout << endl;
    }
}