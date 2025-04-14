#include<bits/stdc++.h>
using namespace std;
// vector<int> twoSum(vector<int>& numbers, int target) {
//     unordered_set<int> myset (numbers.begin(),numbers.end());
//     map<int,int>indexes;
//     vector<int> ans;
//     for(int x = 0 ; x < numbers.size() ; x++){
//         indexes[numbers[x]] = x;  
//     }
//     for(int l = 0 ; l < numbers.size();l++){
//         if( myset.find(target-numbers[l]) != myset.end()){
//             ans.push_back(l+1);
//             ans.push_back(indexes[target-numbers[l]]+1);
//             return ans;
//         }
//     }
// }
// two pointer solution
vector<int> twoSum ( vector<int> & numbers, int target){
    int l = 0 ;
    int r = numbers.size()-1;
    while(l<r){
        int current_sum = numbers[l] + numbers[r];
        if(current_sum < target){
            l++;
        }
        else if(current_sum > target){
            r--;
        }
        else {
            return {l+1,r+1};
        }
    }
    return {};
}
int main()
{
    vector<int> numbers = {-3,-2,1,7,9};
    int target = 5;
    vector <int> ans =twoSum(numbers,target);
    for(auto x : ans) cout << x <<" ";
}