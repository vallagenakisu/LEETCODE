#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    int di[] = {0, 1, 0, -1};
    int dj[] = {1, 0, -1, 0};
    int i = 0, j = -1;
    int total_size = n * m;
    vector<int> ans;
    while (ans.size() < total_size)
    {
        for (int k = 0; k < 4; k++)
        {
            i = i + di[k];
            j = j + dj[k];
            while (i < n and j < m and i >= 0 and j >= 0)
            {
                if (vis[i][j] == 1)
                    break;
                vis[i][j] = 1;
                ans.push_back(matrix[i][j]);
                i = i + di[k];
                j = j + dj[k];
            }
            if (dj[k] != 0)
            {
                j = j - dj[k];
            }
            if (di[k] != 0)
            {
                i = i - di[k];
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix =
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}};
    vector<int> ans = spiralOrder(matrix);
    for (auto x : ans)
        cout << x << " ";
}