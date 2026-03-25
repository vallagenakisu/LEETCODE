#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s , string t )
{
    int l = 0 , r = 0 ;
    int a = s.size() - 1;
    int b = t.size() - 1;
    while(l<=a and r<=b)
    {
        //cout << s[l] << " " << t[r] << endl;
        if(s[l] == t[r])
        {
            l++;
            r++;
        }
        else if(s[l] != t[r])
        {
            r++;
        }
    }
    //cout << l << " " ;
    if(l == a+1) return true;
    else return false;
}


int main()
{
    string s = "abc";
    string t = "ahbgdc";
    cout << isSubsequence(s,t);
}