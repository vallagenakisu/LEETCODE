#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
    int len = s.size();
    int l = 0 ,r = len-1;
    while(l!=r and l < len and r >= 0){
        while(!(s[l] >= 'a' and s[l] <='z' or s[l] >='A' and s[l] <='Z' or s[l] >=  '0' and s[l]<='9') and l < len)l++;
        while(!(s[r] >= 'a' and s[r] <='z' or s[r] >='A' and s[r] <='Z' or s[r] >=  '0' and s[r]<='9') and r >= 0)r--;
        if(l < len and r >=0){
            if(tolower(s[l]) != tolower(s[r])) {return false;}
        }else break;
        l++;r--;
    }
    return true;

}
int main()
{
    string s = "0P";
    cout << isPalindrome(s);
}