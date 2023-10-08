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

ll bin_pow(ll a, ll b, int mod){
    ll res = 1;
    while(b > 0){
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
 
void solve(){
    int n, mod = 1e9+7;
    cin >> n;
    vector<ll> fact(1e6+5);
    vector<ll> inv_fact(1e6+5);
    fact[0] = inv_fact[0] = 1;
    for(int i = 1; i <= 1e6; i++){
        fact[i] = fact[i-1] * i % mod;
        inv_fact[i] = bin_pow(fact[i], mod-2, mod);
    }
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cout << ((fact[a] * inv_fact[b]) % mod) * inv_fact[a-b] % mod << '\n';
    }
}   
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}