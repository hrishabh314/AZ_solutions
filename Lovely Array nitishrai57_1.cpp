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
    int MXN = 1e5;
    vector<int> cnt(MXN+1), vis(MXN+1, -1);

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, cnt[x]++;
    sort(a.begin(), a.end());

    for (int i = 1; i <= MXN; i++) cnt[i] += cnt[i-1];
    
    int ans = 0;
    for (auto x : a) {
        if (vis[x] == -1) {
            vis[x] = 0;
            
            for (int i = 1, la; i <= x; i = la+1) {
                la = x / (x/i);
                vis[x] += x/i * (cnt[la] - cnt[i-1]);
            }
        }

        ans += vis[x];
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    for (int i = 1; i <= tt; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }    
}
