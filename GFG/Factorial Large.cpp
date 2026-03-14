#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> res(10000, 0);
    res[0] = 1;
    int size = 1;
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < size; j++)
        {
            int result = res[j] * i + carry;
            res[j] = result % 10;
            carry = result / 10;
        }
        while(carry >0)
        {
            int result = carry;
            res[size] = result % 10;
            carry = result / 10;
            size++;
        }
    }
    vector<int> ans;
    for (int i = size - 1; i >= 0; i--)
    {
        ans.push_back(res[i]);
    }
    return ans;
}

int main()
{
    vector<int> result = factorial(20);
}