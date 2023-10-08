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

vector<bool> is_prime(1e6+1, 1);
vector<ll> primes;

void sieve(){
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i * i <= 1e6; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 1e6; j += i)
                is_prime[j] = 0;
        }
    }
    for(int i = 2; i <= 1e6; i++)
        if(is_prime[i])
            primes.pb(i);
}

ll bin_pow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b % 2)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

void solve(){
    ll n, cntdiv = 1, sumdiv = 1, mod = 1e9+7;
    cin >> n;
    for(int i = 0; i < primes.size(); i++){
        if(primes[i] * primes[i] > n)
            break;
        if(n % primes[i])
            continue;
        int cnt = 0;
        while(n % primes[i] == 0){
            n /= primes[i];
            cnt++;
        }
        cntdiv *= (cnt+1);
        sumdiv *= (bin_pow(primes[i], cnt+1)-1)/(primes[i] - 1);
        sumdiv %= mod;
    }
    if(n > 1){
        cntdiv *= 2;
        sumdiv *= (n+1);
        sumdiv %= mod;
    }
    cout << cntdiv << ' ' << sumdiv << '\n';
}  
 
int main(){
    //freopen("coborare.in", "r", stdin);
    //freopen("coborare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    sieve();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}