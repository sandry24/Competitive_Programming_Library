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
vi SPF(n+1);

void sieve(){
    SPF[1] = SPF[0] = 0;
    for(int i = 2; i <= n; i++)
        SPF[i] = i;
    for(int i = 2; i * i <= n; i++){
        if(SPF[i] == i){
            for(int j = i * i; j <= n; j += i){
                if(SPF[j] == j)
                    SPF[j] = i;
            }
        }
    }
}

vi prime_fact(int n){
    vi prime_factorization;
    while(n != 1){
        prime_factorization.pb(SPF[n]);
        n /= SPF[n];
    }
    return prime_factorization;
}

void solve(){
    sieve();
    for(int i = 1; i <= 50; i++)
        if(SPF[i] == i)
            cout << i << ' ';
    cout << '\n';
    for(auto i : prime_fact(68222))
        cout << i << ' ';
    cout << '\n';
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