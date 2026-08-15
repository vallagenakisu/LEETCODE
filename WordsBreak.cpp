#include <bits/stdc++.h>
using namespace std;
unordered_set<string> st;
vector<int> memo;
bool f(int start , string &s)
{
    if(start == s.size()) return true;
    if(memo[start] != -1) return memo[start];
    for(int end = start + 1; end <= s.size() ; end++)
    {
        string newword = s.substr(start,end - start);
        if(st.count(newword) && f(end,s))
        {
            return memo[start] = 1;
        }
    }
    return memo[start] = 0;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    st = unordered_set<string> (wordDict.begin() , wordDict.end());
    memo.assign(s.size() , -1);
    return f(0,s);
}
int main()
{
    vector<string> wordDict ={
        "leet",
        "code"
    };
    string s = "leetcode";
    cout << wordBreak(s,wordDict);
}