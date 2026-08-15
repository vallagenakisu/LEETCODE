#include<bits/stdc++.h>
using namespace std;
string choto_ans;
vector<string> boro_ans;
void fun(int n , int open , int close)
{
    if(open == 0 and close == 0)
    {
        boro_ans.push_back(choto_ans);
    }
    if(open > 0)
    {
        choto_ans.push_back('(');
        fun(n,open-1,close);
        choto_ans.pop_back();
    }
    if(close > open and close > 0)
    {
        choto_ans.push_back(')');
        fun(n,open,close-1);
        choto_ans.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    fun(n,n,n);
    for(auto x : boro_ans)
    {
        cout << x << endl;
    }
    return boro_ans;
}

int main()
{
    int n = 2;
    generateParenthesis(n);
}