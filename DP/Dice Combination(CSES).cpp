#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

long long int DiceSum(long long int curr, vector<long long int> &memo) {
    if (curr == 0) return 1;
    if (curr < 0) return 0;

    if (memo[curr] != -1) return memo[curr];
    long long int res = 0;
    for (int i = 1; i <= 6; i++) {
        res = (res + DiceSum(curr - i, memo)) % MOD;
    }

    memo[curr] = res;
    return res;
}

int main() {
    long long int target;
    cin >> target;
    vector<long long int> memo(target + 1, -1);
    cout << DiceSum(target, memo) << endl;
}