#include<bits/stdc++.h>
using namespace std;
 int trap(vector<int>& height) {
    int len = height.size();
    vector<int> prefix_max(len,0);prefix_max[0] = height[0];
    vector<int> suffix_max(len,0);suffix_max[0] = height[len-1];
    for(int i = 1 ; i < len - 1 ; i++){
        prefix_max[i] = max(prefix_max[i-1],height[i]);
    }
    for(int i = len-2 ; i >=0  ; i--){
        suffix_max[i] = max(prefix_max[i+1],height[i]);
    }
    int sum = 0 ;
    for(int i = 1 ; i < len-1 ; i++){
        int res = min(prefix_max[i-1],suffix_max[i+1]) - height[i] ;
       // cout << res << endl;
        if(res>0) sum+=res;
        
    }
    return sum;

}
int main()
{
    vector<int> height = {0,2,0,3,1,0,1,3,2,1};
    vector<int> prefix(5,0);
    //for(auto x : prefix) cout << x << " ";
    cout << trap(height);
}