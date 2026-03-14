#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> stk;
    vector<string> tokens = {"1","2","+","3","*","4","-"};
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+")
        {
            int a = stk.top();
            stk.pop();
            int b =  stk.top();
            stk.pop();
            stk.push(b+a);
            continue;
        }
        if (tokens[i] == "-")
        {
            int a = stk.top();
            stk.pop();
            int b =  stk.top();
            stk.pop();
            stk.push(b-a);
            continue;
        }
        if (tokens[i] == "*")
        {
            int a = stk.top();
            stk.pop();
            int b =  stk.top();
            stk.pop();
            stk.push(b*a);
            continue;
        }
        if (tokens[i] == "/")
        {
            int a = stk.top();
            stk.pop();
            int b =  stk.top();
            stk.pop();
            stk.push(b/a);
            continue;
        }
        stk.push(stoi(tokens[i]));
    }
    cout << stk.top();
}