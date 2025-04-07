#include <bits/stdc++.h>
using namespace std;

string encode(vector<string> &strs)
{
    if(strs.empty()){
        return "";
    }
    string ans;
    for(auto x : strs){
        int len = x.size();
        ans += to_string(len) +"#"+ x + "#";
    }
    return ans;
}

vector<string> decode(string s)
{
    vector<string> ans;
    if(s.empty()){
        return {};
    }
     
    int len = s.size();
    int x;
    for(int i = 0 ; i < len ;i++){
        string digit , ans1;
        int ptr = i,r = 0;
        if(s[ptr] == '0'){
            ans1 = "";
            ans.push_back(ans1);
        }
        while( isdigit(s[ptr]) ) {
            digit.push_back(s[ptr]);
            ptr++;
        }
        int digi = stoi(digit);
        while(true){
            ptr++;
            if(s[ptr]  == '#'){
                if (  digi <= r   )
                break;
            }
            if(ptr>len) break;
            ans1.push_back(s[ptr]);
              
            r++; 
        }
        
        if(ptr>= len ) break;
        i = ptr;
        if(!ans1.empty())
        ans.push_back(ans1);
    }
    return ans;
}
int main()
{
    vector<string> test = {""};
    //cout << encode(test);
    vector<string> ans =  decode(encode(test));
    //cout << ans.size()<<endl;
    for(auto x : ans ){
        cout << x << " ";
    }
}