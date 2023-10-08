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
    //basically backpack doar ca cu books, cost and pages
    int n, x;
    cin >> n >> x;
    vi dp(x+1), prices(n), pages(n);
    for(int i = 0; i < n; i++)
        cin >> prices[i];
    for(int i = 0; i < n; i++)
        cin >> pages[i];
    for(int i = 0; i < n; i++){
        for(int j = x; j >= 0; j--){
            if(j - prices[i] >= 0)
                dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
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