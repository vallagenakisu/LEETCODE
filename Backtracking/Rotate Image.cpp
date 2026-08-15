#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        swap(matrix[i][j] , matrix[j][i]);
    }
    for(auto &x : matrix)
    reverse(x.begin() , x.end());
}
int main()
{
    vector<vector<int> > ans =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate(ans);
}