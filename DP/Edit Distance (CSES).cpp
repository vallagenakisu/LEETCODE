#include<bits/stdc++.h>
using namespace std;
int main()
{
    string n , m ;
    cin >> n >> m;
    int len_n = n.length();
    int len_m = m.length();
    int ans = abs(len_n - len_m);
    int shortest = min(len_m , len_n);
    int match = 0 ;
    for(int i = 0 ; i < shortest ; i++)
    {
        if(m[i] == n[i]) match++;
    }
    
    ans += abs(shortest - match );
    cout << ans ;
}