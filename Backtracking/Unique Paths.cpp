#include <bits/stdc++.h>
using namespace std;
int f(int i ,int j , int m , int n,vector<vector<int>> & memo)
{
    if(memo[i][j] != -1) return memo[i][j];

    if(i == m-1 and j == n-1) return 1;
    if(i >= m or j >= n) return 0;

    return memo[i][j] = f(i+1,j,m,n,memo) + f(i,j+1,m,n,memo);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
    // memset(memo,-1,sizeof(memo));
    return f(0,0,m,n,memo);
}
int main()
{
    cout << uniquePaths(12,15);
}