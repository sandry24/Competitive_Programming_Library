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

vector<ll> get_all_sums(vector<ll> &a, ll l, ll r){
    ll len = r-l+1;
    vector<ll> sums;
    for(ll i = 0; i < (1 << len); i++){
        ll sum = 0;
        for(ll j = 0; j < len; j++){
            if((1 << j) & i)
                sum += a[l+j];
        }
        sums.pb(sum);
    }
    return sums;
}

void solve(){
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> left = get_all_sums(a, 0, n/2-1);
    vector<ll> right = get_all_sums(a, n/2, n-1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    ll ans = 0;
    for(auto i : left){
        int low = lower_bound(right.begin(), right.end(), x-i) - right.begin();
        int up = upper_bound(right.begin(), right.end(), x-i) - right.begin();
        ans += up - low;
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