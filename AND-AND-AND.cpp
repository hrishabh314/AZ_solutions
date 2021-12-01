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

int inf = 1e15;
vector<int> v;

int getAND() {
    int res = 0;
    for (int p = 0; p < 32; p++) {
        if (!v[p]) res += 1ll << p;
    }
    return res;
}

void jodo(int n) {
    for (int p = 0; p < 32; p++) {
        if (!(n & 1)) v[p]++;
        n >>= 1;
    }
}

void hataao(int n) {
    for (int p = 0; p < 32; p++) {
        if (!(n & 1)) v[p]--;
        n >>= 1;
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    v = vector<int>(32);

    for (auto &x : a) cin >> x;

    int tail = 0, head = -1, ans = inf;
    
    while (tail < n) {
        while (head+1 < n && k < getAND()) {
            head++;
            jodo(a[head]);
        }

        int val1 = inf, val2 = getAND();
        if (head-tail+1 >= 2) {
            hataao(a[head]);
            val1 = getAND();
            jodo(a[head]);
        }


        ans = min({ans, abs(k-val1), abs(k-val2)});

        if (tail <= head) {
            hataao(a[tail]);
            tail++;
        } else {
            tail++;
            head = tail-1;
        }
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
