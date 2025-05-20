#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& heights) {
    int len = heights.size();
    int ans = -1 ;
    int l = 0 ;
    int r = len -1 ;
    while( l < r){
        int area = min(heights[l] , heights[r]) * (r-l);
        ans = max (area , ans);
        if(heights[l] < heights[r]){
            l++;
        }
        else {
            r--;
        }
    }
    return ans;
}
int main()
{
    vector<int> heights = {1,7,2,5,4,7,3,6};
    cout << maxArea(heights);
}