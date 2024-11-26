#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums){
    map<int,int> track ;
    for(auto x : nums){
        track[x]++;
    }
    for(auto x : track){
        if(x.second > 1){
        cout <<"true" << endl;
        return true;
        }
    }
    cout <<"false"<<endl;
    return false;

    }
};
