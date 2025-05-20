#include<bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle)
 {
    int hLength = haystack.length();
    int nLength = needle.length();
    if(nLength > hLength) return -1;
    int ans = -1;
    for(int i = 0 ; i < hLength ; i++){
        if(haystack[i] == needle[0]){
            int j = 0 ;
            int k = i;
            ans = i;
            while(haystack[k] == needle[j] and k < hLength and j < nLength){
                //cout << "i = "<<haystack[k] << " j = "<<needle[j]<<" and i =  "<<i<<endl;
                k++;j++;
            }
            if( j == nLength) {return ans; }
            else ans = -1;
        }
    }
    return ans;
 }
int main()
{
    string haystack = "mississippi";
    string needle = "issip";
    cout << strStr(haystack , needle);
}