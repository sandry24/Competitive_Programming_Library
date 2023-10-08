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

void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n+1);
    vector<vi> sparse_table(n+1, vi(25));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sparse_table[i][0] = a[i];
    }
    for(int j = 1; j < 25; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            sparse_table[i][j] = min(sparse_table[i][j-1], sparse_table[i + (1 << (j-1))][j-1]);
        }
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        int w = (int)log2(r-l+1);
        cout << min(sparse_table[l][w], sparse_table[r - (1 << w) + 1][w]) << '\n';
    }
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