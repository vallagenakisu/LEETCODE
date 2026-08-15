#include <bits/stdc++.h>
using namespace std;
int reverseBits(int n)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        result = result << 1;
        if (n & 1 != 0)
        {
            result += 1;
        }
        n = n / 2;
    }
    return result;
}
int main()
{
    cout << reverseBits(2147483644) << endl;
}
