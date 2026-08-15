#include<bits/stdc++.h>
using namespace std;
int expand (string &s , int l , int r )
{
    while(l >= 0 and r < s.size())
    {
        if(s[l] != s[r])
        break;
        else
        {
            r++;
            l--;
        }
    }
    return r-(l+1);
}
string longestPalindrome(string s)
{
    int n = s.size();
    if(n == 0 ) return "";

    int maxlen = 0;
    int start = 0;
    for(int i = 0 ; i < n ; i++)
    {
        //odd length 
        int len1 = expand(s,i,i);
        
        //even length
        int len2 = expand(s,i,i+1);
        int len = max(len1,len2);
        if(len > maxlen)
        {
            maxlen = len;
            start = i - (maxlen - 1)/2 ;
            
        } 
    }
    return s.substr(start , maxlen);
}

int main()
{
    string s = "aba";
    cout << longestPalindrome(s);
}