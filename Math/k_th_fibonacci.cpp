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

ll ans[2][2] = {{1, 0}, {0, 1}}, mult[2][2] = {{1, 1}, {1, 0}}, mod = 1e9+7;
 
void multiply(ll A[2][2], ll B[2][2]){
    ll C[2][2];
    memset(C, 0, sizeof(C));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            A[i][j] = C[i][j];
}
 
void solve(){
    ll n;
    cin >> n;
    while(n){
        if(n & 1)
            multiply(ans, mult);
        multiply(mult, mult);
        n /= 2;
    }
    cout << ans[0][1] << '\n';
}     
 
int main(){
    //freopen("infasuratoare.in", "r", stdin);
    //freopen("infasuratoare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}