#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums) 
{
    unordered_set<int> myset(nums.begin(),nums.end());
    int length = 0 , longest = 0 ;
    for (auto x : myset){
        if( myset.find(x-1) == myset.end()){
            length = 1;
            while(myset.find(x+length) != myset.end()){
                length++;
            } 
        }
        longest = max (longest , length);
    }
    return longest;
}
int main()
{
    vector<int> nums = {0 , 1 ,2, 3, 5 ,9 , 3 ,4 ,5 ,6 ,7 ,8 ,1 ,3 };
    cout << longestConsecutive(nums);
}