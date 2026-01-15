#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int l = 0 ;
    int r = nums.size() -1 ;
    while(l <= r ){
        int mid = l + (r - l) / 2 ;
        if(target == nums[mid] ) return mid;
        if( nums[l] <= nums[mid] ){
            if(target < nums[mid] and target >= nums[l])
                r = mid - 1;
            else 
                l = mid + 1 ;
        }
        else
        {
            if(target > nums[mid] and target <= nums[r])
            {
                l = mid + 1;
            }
            else 
                r = mid - 1;
        }
    }
    return -1 ;    
}
void sol() {
    vector<int> nums = {4,5,6,7,0,1,2,3};
    int target = 2 ;
    cout << search(nums , target);

}

int main() {
    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--) {
        sol();
    }
    return 0;
}