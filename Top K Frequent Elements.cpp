class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    int n ;
    map<int , int > maps;
    n = nums.size();
    for(int i =0 ; i < nums.size() ; i ++ ){
        maps[nums[i]]++;

    }
   multimap<int,int> sol_map;
    for(auto x : maps){
        sol_map.insert({x.second, x.first});
    }
    vector<int> solution(k,0);
    auto it = sol_map.rbegin();
    int count = 0 ;
    while (count < k){
        solution[count] = it->second;
        count++; 
        it++;
    }
    return solution;
    }
};
