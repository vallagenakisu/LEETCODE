#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int len = s.size();
    set<char> st;
    int ans = 0;
    if(len == 0 ) return 0 ;
    int l = 0 , r = 0;
    for(int i = 0 ; i < len ; i++)
    {
        if(!(st.find(s[i]) == st.end()))
        {
            //found repeating element
            ans = max(ans, r-l);
            while(s[l] != s[r])
            {
                st.erase(s[l]);
                l++;
            }
            st.erase(s[l]);
            l++;
            st.insert(s[i]);
            r++;
        }
        else
        {
            st.insert(s[i]);
            r++;
        }
    }
    ans = max(ans,r-l);
    return ans;
}
int main()
{
    string s = "xyzxyzxzabcd";
    // cout << s.size()<<endl;
    cout << lengthOfLongestSubstring(s);
}