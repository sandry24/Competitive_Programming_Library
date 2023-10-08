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

int p1 = 31, p2 = 51, m = 1e9+7;
vector<ll> p1_pow(1505), p2_pow(1505);
 
void solve(){
    string s, b;
    int k, n;
    cin >> s >> b >> k;
    n = s.size();
    set<pair<ll, ll>> st;
    p1_pow[0] = p2_pow[0] = 1;
    for(int i = 1; i < n; i++){
        p1_pow[i] = (p1_pow[i-1] * p1) % m;
        p2_pow[i] = (p2_pow[i-1] * p2) % m;
    }
    for(int i = 0; i < n; i++){
        int cnt = 0;
        ll hash1 = 0, hash2 = 0;
        for(int j = i; j < n; j++){
            if(b[s[j]-'a'] == '0')
                cnt++;
            if(cnt > k)
                break;
            hash1 = (hash1 + (s[j] - 'a' + 1)*p1_pow[j-i]) % m;
            hash2 = (hash2 + (s[j] - 'a' + 1)*p2_pow[j-i]) % m;
            st.insert({hash1, hash2});
        }
    }
    cout << st.size() << '\n';
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