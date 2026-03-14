#include <bits/stdc++.h>
using namespace std;
// naive
// int maxWater(vector<int> &arr)
// {
//     int size = arr.size();
//     int total_water = 0;
//     for (int i = 1; i < size - 1; i++)
//     {
//         int left_max = INT_MIN;
//         int right_max = INT_MIN;
//         // finding left max
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[j] > left_max)
//                 left_max = arr[j];
//         }
//         // finding right max
//         for (int j = i + 1; j < size; j++)
//         {
//             if (arr[j] > right_max)
//                 right_max = arr[j];
//         }
//         // cout << " at " << arr[i] << " left_max = " << left_max << " right_max =" << right_max << " ";
//         int water_level = min(left_max, right_max) - arr[i];
//         // cout << water_level << " ";
//         // cout << endl;
//         if (water_level > 0)
//             total_water += water_level;
//     }
//     return total_water;
// }

// prefix_max suffix_max 
int maxWater(vector<int> &arr)
{
    int size = arr.size();
    int total_water = 0 ;
    vector<int> prefix_max(size , 0 );
    vector<int> suffix_max(size , 0 );
    prefix_max[0] = arr[0];
    for(int i = 1 ; i < size ; i++)
    {
        prefix_max[i] = max(prefix_max[i-1] , arr[i]);
    }
    suffix_max[size - 1 ] = arr[size-1];
    for(int i = size - 2 ; i >=0 ; i--)
    {
        suffix_max[i] = max(suffix_max[i+1] , arr[i]);
    }
    // cout <<"Suffix Max's"<<endl;
    // for(auto x : suffix_max) cout << x << " ";
    // cout << endl ;
    // cout << "Prefix Max's " << endl;
    // for(auto x : prefix_max) cout << x << " ";
    // cout << endl;
    for(int i = 1 ; i < size ; i++)
    {
        int water_level = min(prefix_max[i], suffix_max[i]) - arr[i];
        if(water_level > 0) total_water += water_level;
    }
    return total_water;
}

int main()
{
    vector<int> water = {3, 0, 1, 0, 4, 0, 2};
    cout << maxWater(water);
}