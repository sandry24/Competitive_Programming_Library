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

int p = 31, m = 1e9+7, invp = 129032259;
vector<ll> p_pow(1e6+5), invp_pow(1e6+5), prefix_h(1e6+5);

ll subarr_hash(int l, int r){
    return (prefix_h[r] - prefix_h[l-1] + m) * invp_pow[l-1] % m; 
}
 
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    p_pow[0] = invp_pow[0] = 1;
    for(int i = 1; i <= 1e6; i++){
        p_pow[i] = p_pow[i-1] * p % m;
        invp_pow[i] = invp_pow[i-1] * invp % m;
    }
    for(int i = 1; i <= n; i++)
        prefix_h[i] = (prefix_h[i-1] + (s[i-1] - 'a' + 1) * p_pow[i]) % m;
    for(int i = 1; i <= n; i++){
        bool ok = true;
        ll hash = prefix_h[i];
        for(int j = i+1; j <= n; j += i){
            if(j + i - 1 > n){
                int sz = n - j + 1;
                hash = prefix_h[sz];
            }
            if(subarr_hash(j, min(j+i-1, n)) != hash){
                ok = 0;
                break;
            }
        }
        if(ok)
            cout << i << ' ';
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