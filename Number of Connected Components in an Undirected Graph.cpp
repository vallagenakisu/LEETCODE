#include<bits/stdc++.h>
using namespace std;
void dfs(int i , vector<int> adj[] , vector<int> &vis)
{
    vis[i] = 1;
    for(auto x : adj[i])
    {
        if(!vis[x])
        {
            dfs(x,adj,vis);
        }
    }
}
int countComponents(int n, vector<vector<int>>& edges)
{
    vector<int> adj[2009];
    vector<int> vis(2009);
    for(int i = 0 ; i < n ; i++) vis[i] = 0;
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    int count = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis);
            count++;
        }
        
    }
    return count;
}
int main()
{
    int n = 5 ;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4}};
    cout << countComponents(5,edges);
}