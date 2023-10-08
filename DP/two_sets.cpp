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
    //in how many ways can you split all numbers 1 .. n in 2 sets with equal sums
    ll n, sum, mod = 1e9+7;
    cin >> n;
    sum = n*(n+1)/2;
    if(sum % 2){
        cout << 0 << '\n';
        return;
    }
    vector<ll> dp(sum+1);
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = sum; j >= 0; j--){
            if(j - i >= 0){
                dp[j] += dp[j-i];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[sum/2] << '\n';
}
 
int main(){
    //freopen("rucsac.in", "r", stdin);
    //freopen("rucsac.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}