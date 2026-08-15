#include <bits/stdc++.h>
using namespace std;
int hammingWeight(int n)
{
    int result = 0;
    while(n)
    {
        if(n % 2 != 0) result++;
        n = n / 2;
    }
    return result;
}
int main()
{
    cout << hammingWeight(2147483645) << endl;
}