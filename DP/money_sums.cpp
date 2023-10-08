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
    //given n certain values, output all the possible sums you can do with them
    int n;
    cin >> n;
    vi a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<bool> dp(sum+1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= 0; j--){
            if(j - a[i] >= 0 && dp[j-a[i]])
                dp[j] = dp[j-a[i]];
        }
    }
    vi ans; 
    for(int i = 1; i <= sum; i++){
        if(dp[i])
            ans.pb(i);
    }
    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i << ' ';
    cout << '\n';
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