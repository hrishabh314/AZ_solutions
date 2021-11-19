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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, c; cin >> n >> m >> c;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    int lo = 0, hi = a[n-1] - a[0], ans = hi;

    while (lo <= hi) {
        //cerr << lo << ' ' << hi << '\n';
        int mid = (lo + hi) / 2;

        int i = 0, busses = 0;
        while (i < n) {
            int j = upper_bound(a.begin(), a.end(), a[i]+mid) - a.begin();
            j--;

            j = min(i+c-1, j);
            busses++;
            i = j+1;
        }

        if (busses <= m) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    cout << ans;
}
