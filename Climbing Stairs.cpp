#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) {
        memo = vector<int>(n + 1, -1);
        return helper(n);
    }
    int helper(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (memo[n] != -1) return memo[n];
        memo[n] = helper(n - 1) + helper(n - 2);
        return memo[n];
    }
};