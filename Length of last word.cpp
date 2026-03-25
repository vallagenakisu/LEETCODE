#include <bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s)
{
    int i = s.size() - 1;
    // cout << i;
    while(s[i] == ' ' && i >=0) i--;
    // cout << i ;
    int ans = 0 ;
    while( i >= 0 and  s[i] !=' ')
    {
        i--;
        ans++;
    }
    return ans;
}

int main()
{
    string a = "a";
    cout << lengthOfLastWord(a);
}