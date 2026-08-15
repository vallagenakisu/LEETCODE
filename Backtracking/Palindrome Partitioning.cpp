#include <bits/stdc++.h>
using namespace std;
int n;
string choto;
vector<string> boro;
vector<vector<string>> ans;
bool isPalindrome(string a)
{
    if (a.size() == 1)
        return true;
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        if (a[l] != a[r])
            return false;
        l++;
        r--;
    }
    return true;
}
void fun(string s, int i)
{
    if (i != 0 and isPalindrome(choto))
    {
        boro.push_back(choto);
    }

    if (i == n)
    {
        ans.push_back(boro);
    }
    for (int j = i; j < n; j++)
    {
        if (i == 0)
        {
            choto.push_back(s[j]);
            fun(s, j + 1);
            choto.pop_back();
        }
        if (i != 0 and i == j)
        {
            choto.push_back(s[j]);
            fun(s, j + 1);
            choto.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    n = s.size();
    fun(s, 0);
    return ans;
}
int main()
{
    string s = "aab";
    n = s.size();
    fun(s, 0);
    for (auto x : boro)
        cout << x << endl;
}