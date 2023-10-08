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

const int maxn = 5005, maxk = 1e5+5, maxchar = 1e6+5;
ll p_pow[maxchar], invp_pow[maxchar], prefix_h[maxn];
int dp[maxn];
vector<vector<pi>> dict(26);
int p = 31, inv_p = 129032259, m = 1e9+7;
 
int subarr_hash(int l, int r){
    return (prefix_h[r] - prefix_h[l-1] + m) * invp_pow[l-1] % m;
}
 
void solve(){
    string s, t;
    cin >> s;
    int n = s.size(), k;
    cin >> k;
    p_pow[0] = invp_pow[0] = 1;
    for(int i = 1; i < maxchar; i++){
        p_pow[i] = p_pow[i-1] * p % m;
        invp_pow[i] = invp_pow[i-1] * inv_p % m;
    }
    for(int i = 1; i <= n; i++)
        prefix_h[i] = (prefix_h[i-1] + (s[i-1] - 'a' + 1) * p_pow[i-1]) % m;
    for(int i = 0; i < k; i++){
        cin >> t;
        ll hash = 0;
        for(int j = 0; j < t.size(); j++)
            hash = (hash + (t[j] - 'a' + 1) * p_pow[j]) % m;
        dict[t.back() - 'a'].pb({hash, t.size()});
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(auto elem : dict[s[i-1] - 'a']){
            if(i - elem.s + 1 >= 1 && elem.f == subarr_hash(i - elem.s + 1, i)){
                dp[i] = (dp[i] + dp[i - elem.s]) % m;
            }
        }
    }
    cout << dp[n] << '\n';
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