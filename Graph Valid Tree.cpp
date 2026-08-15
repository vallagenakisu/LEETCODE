#include<bits/stdc++.h>
using namespace std;
bool dfs(int i , vector<int> adj[] , vector<int> &vis , vector<int> &parent)
{
    vis[i] = 1;
    for(auto x : adj[i])
    {
        if(!vis[x])
        {
            parent[x] = i;
            if(!dfs(x,adj,vis,parent)) return false;
        }
        else if(x != parent[i])
        {
            return false;
        }
    }
    return true;
}
bool validTree(int n, vector<vector<int>>& edges)
{
    vector<int> adj[100];
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> vis(100);
    
    vector<int> parent(100);
    for(int i = 0 ; i < 100 ; i++)
    {
        vis[i] = 0;
        parent[i] = 0;
    }
    parent[0] = -1;
    bool ans = dfs(0,adj,vis,parent);
    for(int i = 0 ; i < n ; i++)
    {
        if(!vis[i]) return false;
    }
    return ans;
}


int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {1,3},{1,4}};
    cout << validTree(n,edges);
}