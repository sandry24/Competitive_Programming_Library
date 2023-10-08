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
    //in one step you can subtract a digit, how many steps to make it 0
    int n;
    cin >> n;
    vi dp(n+1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        for(int j = 0; j < s.size(); j++){
            if(i - s[j] + '0' >= 0)
                dp[i] = min(dp[i], dp[i - s[j] + '0'] + 1);
        }
    }
    cout << dp[n] << '\n';
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