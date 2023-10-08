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

ll bin_pow(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b % 2)
            res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

int phi(int n){
    int result = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

void solve(){
    ll a, m;
    cin >> a >> m;
    cout << bin_pow(a, phi(m)-1, m) << '\n';
}  
 
int main(){
    //freopen("inversmodular.in", "r", stdin);
    //freopen("inversmodular.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}