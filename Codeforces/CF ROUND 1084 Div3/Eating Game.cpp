#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int cnt = 0;
    for (int x : a) {
        if (x == mx) cnt++;
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}