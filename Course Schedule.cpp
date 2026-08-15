#include<bits/stdc++.h>
using namespace std;

bool dfs(int i , vector<int> adj[] , vector<int> &vis)
{
    if(vis[i] == -1 ) return false;
    if(vis[i] == 1) return true;
    vis[i] = -1;
    for(auto x : adj[i])
    {
        if(!dfs(x,adj,vis)) return false;
    }
    vis[i] = 1;
    return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> adj[numCourses];
    vector<int> vis(numCourses,0);
    for(auto x : prerequisites)
    {
        adj[x[0]].push_back(x[1]);
    }
    // for(int i = 0 ; i < numCourses; i++)
    // {
    //     cout <<i << " ";
    //     for(auto x : adj[i])
    //     cout << x <<" ";
    //     cout << endl;
    // }
    for(int i = 0 ; i < numCourses ; i++)
    {
        if(!dfs(i,adj,vis)) return false;
    }
    return true;
}

int main()
{
    int numCourses = 5;
    vector<vector<int>> prerequisites = {
        {4,4}
    };
    cout << canFinish(numCourses, prerequisites);
}