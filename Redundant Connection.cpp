#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dfs(int i , vector<int> adj[] , vector<int> &vis , vector<int> &parent)
{
    vector<pair<int,int>> ans;
    vis[i] = 1;
    cout << i<< endl;
    for(auto x : adj[i])
    {
        if(!vis[x])
        {
            parent[x] = i;
            dfs(x,adj,vis,parent);
        }
        else if( x != parent[i])
        {
            // cout << i << " " << x <<endl;
            ans.push_back({i,x});
        }
    }
    return ans;
}
vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
    int n = edges.size();
    vector<int> adj[n+3];
    vector<int> vis(n+3,0);
    vector<int> parent(n+3 , 0);
    for(auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> last = edges[n-1];
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    vector<int> ans;
    while(!q.empty())
    {
        int i = q.front();
        vis[i] = 1;
        q.pop();
        for(auto x : adj[i])
        {
            if(!vis[x])
            {
                parent[x] = i;
                q.push(x);
            }
            else if(x != parent[i])
            {
                // cout << x <<" "<< i <<endl;
                ans = {x,i};
            }
        }
    }
    for(auto x : ans)
    cout << x<< " ";
    return ans;
}
int main()
{
    vector<vector<int>> edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    findRedundantConnection(edges);
}