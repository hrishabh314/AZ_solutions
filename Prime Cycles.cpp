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

set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
vector<bool> isPrime(38), isAvail(20);
int n, ans = 0;
vector<int> v = {1};

void rec(int level = 1) {
    if (level == n) {
        if (isPrime[1 + v.back()]) {
            ans++;
        }
    } else {
        for (int i = 2; i <= n; i++) {
            if (isAvail[i] && isPrime[v.back() + i]) {
                isAvail[i] = 0;
                v.push_back(i);
                    
                rec(level + 1);

                isAvail[i] = 1;
                v.pop_back();
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 3; i <= 37; i++) {
        if (primes.find(i) != primes.end()) isPrime[i] = 1;
    }
    for (int i = 2; i <= 19; i++) {
        isAvail[i] = 1;
    }

    cin >> n;
    rec();
    cout << ans;
}
