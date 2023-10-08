#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

vi st(4*200005);

void build(vi &a, int v, int tl, int tr){
    if(tl == tr){
        st[v] = a[tl];
    } else {
        int tm = (tl+tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(tl == l && tr == r)
        return st[v];
    int tm = (tl+tr)/2;
    return max(query(v*2, tl, tm, l, min(tm, r)), 
        query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int new_val, int pos){
    if(tl == tr){
        st[v] = new_val;
    } else {
        int tm = (tl+tr)/2;
        if(pos <= tm)
            update(v*2, tl, tm, new_val, pos);
        else
            update(v*2+1, tm+1, tr, new_val, pos);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n-1);
    cout << query(1, 0, n-1, 0, 2) << '\n';
    update(1, 0, n-1, 1, 2);
    cout << query(1, 0, n-1, 0, 2) << '\n';
}
 
int main(){
    //freopen("coborare.in", "r", stdin);
    //freopen("coborare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}