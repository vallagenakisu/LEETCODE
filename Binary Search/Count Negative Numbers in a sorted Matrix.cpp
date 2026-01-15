#include <bits/stdc++.h>
using namespace std;

int firsNegative(vector<int> array )
{
    int len = array.size();
    int l = 0 , r = len - 1 ;
    int ans = -1;
    while(l<=r)
    {
        int mid = l + ( r - l )/2;
        if(array[mid] >= 0 )
        {
            l = mid + 1 ;
        }
        else 
        {
            ans = mid;
            r = mid - 1 ;
        }
    }
    if(ans == -1 ) return 0;
    else return len - ans ;
}


int countNegatives(vector<vector<int>> &grid)
{
    int ans = 0;
    for(auto x : grid)
    {
        ans = ans + firsNegative(x);
    }
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{4,3,2,-1}, {3,2,1,-1}, {1,1-1,-2} , {-1,-1,-2,-3}};
    cout << countNegatives(grid);
}