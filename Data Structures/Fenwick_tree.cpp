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

int n;
vi BIT(200005);

void add(int x, int delta){
    for(; x <= n; x += x & -x)
        BIT[x] += delta;
}

int sum(int x){
    int ans = 0;
    for(; x > 0; x -= x & -x)
        ans += BIT[x];
    return ans;
}

void solve(){
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        add(i+1, a[i]);
    }
    cout << sum(3) - sum(1) << '\n';
    add(2, 2);
    cout << sum(3) - sum(1) << '\n';
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