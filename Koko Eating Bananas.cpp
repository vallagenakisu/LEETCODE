#include<bits/stdc++.h>
using namespace std;
int minEatingSpeed(vector<int> &piles , int h )
{
    int l = 1 , r = 1e9+3;
    int n = piles.size();
    int ans = -1 ;
    while( l <= r )
    {
        bool possible = 0;
        int mid = l + (r-l)/2 ;
        // 1 4 3 2
        int total_hours = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
            total_hours += ceil( piles[i]*1.0/mid );
        }
        if(total_hours <= h) possible = 1;
        if(possible)
        {
            r = mid - 1 ;
            ans = mid ;
        }
        else 
        {
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{

}