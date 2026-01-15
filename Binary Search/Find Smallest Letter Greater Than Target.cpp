#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int len = letters.size();
    int l = 0, r = len - 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (letters[mid] > target)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return letters[ans];
}
int main()
{
    vector<char> letters = {'c','f','j'};
    char target = 'a';
    cout << nextGreatestLetter(letters, target);
}