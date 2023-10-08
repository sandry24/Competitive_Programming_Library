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
vector<bool> col(50), d1(50), d2(50);
vi ans;

void all_possible(int row){
    if(row == n){
        for(auto i : ans)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(!col[i] && !d1[n-i+row] && !d2[i+row]){
            col[i] = d1[n-i+row] = d2[i+row] = 1;
            ans.pb(i+1);
            all_possible(row+1);
            col[i] = d1[n-i+row] = d2[i+row] = 0;
            ans.pop_back();
        }
    }
}

void solve(){
    cin >> n;
    all_possible(0);
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