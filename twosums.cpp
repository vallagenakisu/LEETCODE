#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int>ans;
    map<int,int> track;
    for(int i = 0 ; i < n ; i++){
        track[nums[i]] = i+1;
    }
    for(int i =1; i<=n; i++){
        int j = target - nums[i-1] ;
        if(track[j] and i != track[j] ){
            ans.push_back(i-1);
            ans.push_back(track[j]-1);
            break;
        }
    }
    return ans;
    }      
};
