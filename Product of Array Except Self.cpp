#include<bits/stdc++.h>
using namespace std;
//division solution
// vector<int> productExceptSelf(vector<int>& nums) {

//     int prod = 1 , flag = 0 ;
//     int len = nums.size();
//     for(int i =0 ; i < len ; i++ ){
//         if(nums[i] != 0 )
//         prod = prod * nums[i];
//         else 
//         flag++;
//     }

//     // cout << "flag " << flag << endl;
//     // cout << "flag " << prod << endl;
//     if(flag > 1 ){
//         vector<int> ans(len, 0);
//         return ans;
//     }
//     else if(flag == 0 ){
//         vector<int> ans(len , prod );
//         for(int i = 0 ; i < len ; i++){
//             if(nums[i] != 0 )
//             ans[i] = ans[i] / nums[i];

//         }
//         return ans;
//     }
//     else if(flag == 1 ){
//         vector<int> ans(len , 0 );
//         for(int i = 0 ; i < len ; i++){
//             if(nums[i] == 0)
//             nums[i] = prod;

//         }
//         return ans;
//     }

// }
//prefix postfix solution
vector<int> productExceptSelf(vector<int>& nums){
    int len = nums.size();
    vector<int> ans(len);
    ans[0] = 1;
    ans[len-1] = 1;
    //calculate prefix 
    for(int i = 1 ; i < len ; i++){
        ans[i] = ans[i-1] * nums[i-1];
    } 
    int var = 1;
    //calculate postfix
    for(int i = len - 2 ; i>=0 ; i--){
        var = var * nums[i+1];
        ans[i] = ans[i] * var;  
    }
    return ans; 

}
int main()
{
    vector<int> num = {1,0,4,6};
    auto x = productExceptSelf(num);
    for(auto y : x )
    cout << y << " ";
}