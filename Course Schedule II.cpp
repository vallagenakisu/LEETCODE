#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> graph[numCourses];
    vector<int> indegree(numCourses,0);
    vector<int> vis(numCourses , 0);
    int m = prerequisites.size();
    for(auto x : prerequisites)
    {
        // 1 0 
        graph[x[1]].push_back(x[0]);
        indegree[x[0]]++;
    }
    queue<int> q;
    for(int i = 0 ; i < numCourses;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    vector<int> ans;
    while( ans.size() < numCourses )
    {
        if(q.empty())
        {
            vector<int> empty;
            return empty;
        }
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        // vis[cur] = 1;
        for(auto x : graph[cur])
        {
            indegree[x]--;
            if(!vis[x] and indegree[x] == 0)
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    return ans;
}


int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{0,1},{1,2},{2,3}};
    vector<int> order = findOrder(numCourses, prerequisites);
    for(int x : order) {
        cout << x << " ";
    }
    cout << endl;
    // return 0;
}