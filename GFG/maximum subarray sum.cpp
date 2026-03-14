#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int> &arr)
{
    int size = arr.size();
    int max_end_sum = INT_MIN ;
    int current_sum = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        current_sum = current_sum + arr[i];
        max_end_sum = max(max_end_sum, current_sum);
        if(current_sum < 0)
        {
            current_sum = 0 ;
        }
    }
    return max_end_sum;
}
int main()
{
    vector<int> arr = {-3, -2, -6, -1, -7, -4};
    cout << maxSubarraySum(arr);
}