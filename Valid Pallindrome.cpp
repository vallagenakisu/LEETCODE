#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {

        while(!isalnum(s[l]) and l < r)
            l++;
        while(!isalnum(s[r]) and l < r)
            r--;
        s[l] = tolower(s[l]);
        s[r] = tolower(s[r]);
        if (s[l] != s[r])
        {
            //cout << s[l] << " " << s[r] << endl;
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main()
{
    string s = "0P";
    cout << isPalindrome(s);
}