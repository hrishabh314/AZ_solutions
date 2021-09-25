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


//----------------------fastpow----------------------

int power(int x, int y, int p) {  //x^y % p in logy
    int res=1; x=x%p;

    while (y>0) {
        if (y&1)  
            res=(res*x)%p; 
        y>>=1;  
        x = (x*x)%p;  
    }  
    return res;  
}

//----------------------fastpow----------------------

int p;

int func(int a, char op, int b) {
    if (op == '+') {
        return (a + b) % p;
    } else if (op == '-') {
        return ((a - b) % p + p) % p;
    } else if (op == '/') {
        b = power(b, p-2, p);
    }

    return a * b % p;
}

void solve() {
    char ch, op1, op2;
    int a, b, c;
    string s;
    cin >> ch >> a >> op1 >> b >> op2 >> c >> ch >> s >> p;

    if (op1 == '*' || op1 == '/') {
        cout << func(func(a, op1, b), op2, c) << '\n';
    } else {
        cout << func(a, op1, func(b, op2, c)) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    for (int i = 1; i <= tt; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }    
}
