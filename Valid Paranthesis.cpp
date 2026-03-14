#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    int len = s.size();
    if(len == 1 ) return false;
    stack<char> st;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' or s[i] == '[' or s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty()) return false;
            if( (s[i] == ')' and st.top() == '(') or (s[i] == ']' and st.top() == '[') or (s[i] == '}' and st.top() == '{'))
            {
                st.pop();
            }
            else return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cin >> s;
    cout << isValid(s);
}