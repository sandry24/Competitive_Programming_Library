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
    //calculate the edit distance between 2 strings
    //in one move you can replace, delete or add a character
    string s, t;
    cin >> s >> t;
    vector<vi> dp(s.size()+1, vi(t.size()+1, 1e9));
    dp[0][0] = 0;
    for(int i = 0; i <= s.size(); i++){
        for(int j = 0; j <= t.size(); j++){
            if(i)
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            if(j)
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            if(i && j)
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s[i-1] != t[j-1]));
        }
    }
    cout << dp[s.size()][t.size()] << '\n';
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