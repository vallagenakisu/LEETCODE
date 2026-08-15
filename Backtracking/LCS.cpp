#include<bits/stdc++.h>
using namespace std;
const int N = 3e3+9;
int memo[N][N];
string s,t;
int lcs(int l , int r)
{
    if(l < 0 or r < 0)
    {
        return 0;
    }
    if(memo[l][r] != -1) return memo[l][r];
    if(s[l] == t[r])
    {
        return memo[l][r] = 1 + lcs(l-1,r-1);
    }
    else 
    return memo[l][r] = max(lcs(l-1,r) , lcs(l,r-1)); 
}
void print(int l , int r )
{
    if(l < 0 or r < 0) return;
    if(s[l] == t[r]) 
    {
        print(l-1,r-1);
        cout << s[l];
        return;
    }
    else 
    {
        int up = lcs(l-1 ,r);
        int left = lcs(l,r-1);
        if(up > left)
        {
            print(l-1,r);
        }
        else 
        {
            print(l,r-1);
        }
    }
}
int main()
{
    cin >> s >> t;
    int l = s.size() - 1 ;
    int r = t.size() - 1 ;
    memset(memo,-1,sizeof(memo));
    lcs(l,r);
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            if(memo[i][j] == -1 ) cout << 0 << " ";
            else cout << memo[i][j]<< " ";
        }
        cout << endl;
    }
    print(l,r);
}