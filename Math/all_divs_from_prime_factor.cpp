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

vector<pi> prime_divs;

void generate_divisors(int ind, int div){
    if(ind == prime_divs.size()){
        cout << div << ' ';
        return;
    }
    for(int i = 0; i <= prime_divs[ind].s; i++){
        generate_divisors(ind+1, div);
        div *= prime_divs[ind].f;
    }
}

void prime_factor(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i)
            continue;
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        prime_divs.pb({i, cnt});
    }
    if(n > 1)
        prime_divs.pb({n, 1});
}

void solve(){
    int n;
    cin >> n;
    prime_factor(n);
    generate_divisors(0, 1);
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