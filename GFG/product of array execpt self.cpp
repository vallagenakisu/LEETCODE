#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> & arr)
{
    int total_product = 1 ;
    int zero_flag = 0;
    int zero_index = -1;
    int size = arr.size();
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] != 0){
        total_product = total_product * arr[i];
        }
        else{
            zero_flag++;
            zero_index = i;
        }
    }
    vector<int> ans(size , 0 );
    if(zero_flag == 1)
    {
        ans[zero_index] = total_product;
        return ans;
    }
    else if(zero_flag > 1)
    {
        return ans;
    }
    for(int i = 0 ; i < size ; i++ )
    {
        if(arr[i] != 0 ){
            ans[i] = total_product / arr[i];
        }
    }
    return ans;
}
int main()
{
    vector<int> input = {12,0};
    auto ans = productExceptSelf(input);
    for(auto x : ans)
    cout << x <<" ";

}