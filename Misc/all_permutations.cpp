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

vi a;

void all_perm(int l, int r){
    if(l == r){
        for(auto i : a)
            cout << i << ' ';
        cout << '\n';
    } else {
        for(int i = l; i < r; i++){
            swap(a[l], a[i]);
            all_perm(l+1, r);
            swap(a[l], a[i]);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    a = vi(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    all_perm(0, n);
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