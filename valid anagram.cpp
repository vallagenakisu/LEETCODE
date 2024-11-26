#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.length() != t.length() ){
        cout << "false";
        return false;
    }
    map<char,int> s_map;
    map<char,int> t_map;
    for(int i =0 ; i < s.length();i++){
        s_map[s[i]]++;
        t_map[t[i]]++;
    }
    for(char i = 'a' ; i<='z';i++){
        if(s_map[i] != t_map[i]){
            cout <<"false";
            return false;
        }
    }
    cout <<"true";
    return true;
        
    }
};
