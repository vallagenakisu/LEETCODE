#include<bits/stdc++.h>
using namespace std;
int findDuplicate(std::vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return num;
            }
            seen.insert(num);
        }
        return -1;
}
int main()
{
    vector<int> nums = {1,2,3,2,2,4};
    cout << findDuplicate(nums);
}