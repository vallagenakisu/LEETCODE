#include <bits/stdc++.h>
using namespace std;

int f(int i, string s, vector<int>& dp)
{
    if (i == s.size()) return 1;
    if (dp[i] != -1) return dp[i];

    int ans = 0;

    if (s[i] != '0')
        ans += f(i + 1, s, dp);

    if (i + 1 < s.size())
    {
        int two = stoi(s.substr(i, 2));
        if (two >= 10 && two <= 26)
            ans += f(i + 2, s, dp);
    }

    return dp[i] = ans;
}

int numDecodings(string s)
{
    vector<int> dp(s.size() + 1, -1);
    return f(0, s, dp);
}

int main()
{
    string s = "226";
    cout << numDecodings(s) << endl;
    return 0;
}