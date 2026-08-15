#include<bits/stdc++.h>
using namespace std;
int expand(string &s , int l , int r)
{
    int counter = 0;
    while( l >= 0 and r < s.size())
    {
        if(s[l] != s[r])
        break;
        else
        {
            r++;
            l--;
            counter++;
        }
    }
    return counter;
}
int countSubstrings(string s)
{
    int n = s.size();
    if(n == 0) return 0;
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        //odd length
        int c1 = expand(s,i,i);
        // even length
        int c2 = expand(s,i,i+1);
        ans = ans + c1 + c2;
    }
    return ans;
}

int main()
{
    string a = "abc";
    cout << countSubstrings(a);

}