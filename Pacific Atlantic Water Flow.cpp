#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> pacific(n,(vector<int>(m,0)));
    vector<vector<int>> atlantic(n,(vector<int>(m,0)));
    queue<pair<int,int>> pq; 
    queue<pair<int,int>> at;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(j == m -1 or i == n - 1) 
            {
                at.push({i,j});
                atlantic[i][j] = 1;
            }
            if(i== 0 or j == 0) 
            {
                pq.push({i,j});
                pacific[i][j] = 1;
            }
        }
    }

    // iterate for pacific 
    while(!pq.empty())
    {
        auto[i,j] = pq.front();
        pq.pop();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k = 0 ; k < 4 ; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 and ni < n and nj >=0 and nj < m)
            {
                if(heights[ni][nj] >= heights[i][j] and pacific[ni][nj] == 0)
                {
                    pacific[ni][nj] = 1;
                    pq.push({ni,nj});
                }
            }
        }
    }
    // iterate for atlantic 
    while(!at.empty())
    {
        auto[i,j] = at.front();
        at.pop();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k = 0 ; k < 4 ; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 and ni < n and nj >=0 and nj < m)
            {
                if(heights[ni][nj] >= heights[i][j] and atlantic[ni][nj] == 0)
                {
                    atlantic[ni][nj] = 1;
                    at.push({ni,nj});
                }
            }
        }
    }
    //now common 
    vector<vector<int>> ans;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(pacific[i][j] and atlantic[i][j])
            {
                // vector<int> buffer = ;
                ans.push_back({i,j});
            }
        }
    }
    return ans;       
}

int main()
{
    vector<vector<int>> heights = {
        {0,0},
        {1,0}
    };
    vector<vector<int>> ans = pacificAtlantic(heights);
    for(auto x : ans)
    {
        for(auto y : x)
        cout << y <<" ";
        cout <<endl;
    }
}