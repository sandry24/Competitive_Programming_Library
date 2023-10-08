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
 
vector<ll> st(8e5+5), lazy_add(8e5+5), lazy_set(8e5+5);
 
void build(int v, int tl, int tr, vi &a){
    if(tl == tr){
        st[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm, a);
        build(v*2+1, tm+1, tr, a);
        st[v] = st[v*2] + st[v*2+1];
    }
}
 
void push(int v, int tl, int tr){
    if(tl > tr)
        return;
    if(lazy_set[v]){
        st[v] = (lazy_set[v] + lazy_add[v]) * (tr - tl + 1);
        if(tl < tr){
            lazy_add[v*2] = lazy_add[v*2+1] = lazy_add[v];
            lazy_set[v*2] = lazy_set[v*2+1] = lazy_set[v];
        }
    } else {
        st[v] += lazy_add[v] * (tr - tl + 1);
        if(tl < tr){
            lazy_add[v*2] += lazy_add[v];
            lazy_add[v*2+1] += lazy_add[v];
        }
    }
    lazy_add[v] = lazy_set[v] = 0;
}
 
void update_add(int v, int tl, int tr, int l, int r, int add){
    push(v, tl, tr);
    if(tl > r || tr < l)
        return;
    if(l <= tl && r >= tr){
        lazy_add[v] += add;
        push(v, tl, tr);
    } else {
        int tm = (tl + tr) / 2;
        update_add(v*2, tl, tm, l, r, add);
        update_add(v*2+1, tm+1, tr, l, r, add);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void update_set(int v, int tl, int tr, int l, int r, int val){
    push(v, tl, tr);
    if(tl > r || tr < l)
        return;
    if(l <= tl && r >= tr){
        lazy_set[v] = val;
        lazy_add[v] = 0;
        push(v, tl, tr);
    } else {
        int tm = (tl + tr) / 2;
        update_set(v*2, tl, tm, l, r, val);
        update_set(v*2+1, tm+1, tr, l, r, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}
 
ll query(int v, int tl, int tr, int l, int r){
    push(v, tl, tr);
    if(tl > r || tr < l)
        return 0;
    if(l <= tl && r >= tr)
        return st[v];
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, r) + 
            query(v*2+1, tm+1, tr, l, r);
}

int find(int v, int tl, int tr, int pos){
    push(v, tl, tr);
    if(tl == tr)
        return st[v];
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        return find(v*2, tl, tm, pos);
    else
        return find(v*2+1, tm+1, tr, pos);
}
 
void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n-1, a);
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int a, b, x;
            cin >> a >> b >> x;
            a--; b--;
            update_add(1, 0, n-1, a, b, x);
        } else if(t == 2){
            int a, b, x;
            cin >> a >> b >> x;
            a--; b--;
            update_set(1, 0, n-1, a, b, x);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << query(1, 0, n-1, a, b) << "\n";
        }
        /*for(int i = 0; i < n; i++){
            //cout << i << ": " << find(1, 0, n-1, i) << '\n';
            //find(1, 0, n-1, i);
        }
        cout << '\n';*/
    }
}   

int main(){
    //freopen("infasuratoare.in", "r", stdin);
    //freopen("infasuratoare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}