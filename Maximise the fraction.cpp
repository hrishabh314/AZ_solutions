#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type,
      less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    long double lo = 0, hi = 1e9, ans = 0;
    for (int j = 0; j < 500; j++) {
        long double mid = (lo + hi) / 2, sum = 0;
        vector<long double> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = a[i] - mid*b[i];
        }
        sort(v.rbegin(), v.rend());

        for (int i = 0; i < k; i++) sum += v[i];

        //cerr << fixed << setprecision(2) << lo << ' ' << hi << ' ' << sum << '\n';

        if (sum >= 0) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    for (int i = 1; i <= tt; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }    
}