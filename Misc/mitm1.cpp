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

vector<ll> sums, a;

void all_sums(int l, int r, ll sum){
    if(l == r){
        sums.pb(sum);
    } else {
        all_sums(l+1, r, sum);
        all_sums(l+1, r, sum + a[l]);
    }
}

void solve(){
    ll n, x;
    cin >> n >> x;
    a = vector<ll>(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    all_sums(0, n/2, 0);
    vector<ll> left = sums;
    sums.clear();
    all_sums(n/2, n, 0);
    vector<ll> right = sums;
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    ll ans = 0;
    for(auto i : left){
        int l = lower_bound(right.begin(), right.end(), x-i) - right.begin();
        int r = upper_bound(right.begin(), right.end(), x-i) - right.begin();
        ans += r-l;
    }
    cout << ans << '\n';
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