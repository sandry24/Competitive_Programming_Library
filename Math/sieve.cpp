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

int n = 1e6;
vector<bool> is_prime(n+1, 1);

void sieve(){
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
}

void solve(){
    sieve();
    for(int i = 1; i <= 50; i++)
        if(is_prime[i])
            cout << i << ' ';
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