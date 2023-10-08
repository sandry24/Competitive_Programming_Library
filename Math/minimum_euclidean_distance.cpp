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
 
void solve(){
    int n;
    cin >> n;
    // pts {x, y}
    vector<pair<ll, ll>> pts(n);
    for(int i = 0; i < n; i++)
        cin >> pts[i].f >> pts[i].s;
    sort(pts.begin(), pts.end());
    //set {y, x}
    set<pair<ll, ll>> s;
    ll best_dist = 9e18;
    int j = 0;
    for(int i = 0; i < n; i++){
        ll d = ceil(sqrtl(best_dist));
        while(j < n && pts[i].f - pts[j].f >= d){
            s.erase({pts[j].s, pts[j].f});
            j++;
        }
        //search the interval [y-d] -> [y+d] from our current points
        auto l = s.lower_bound({pts[i].s - d, pts[i].f});
        auto r = s.upper_bound({pts[i].s + d, pts[i].f});
        for(auto it = l; it != r; ++it){
            ll diffx = pts[i].f - it->second;
            ll diffy = pts[i].s - it->first;
            best_dist = min(best_dist, diffx*diffx + diffy*diffy);
        }
        s.insert({pts[i].s, pts[i].f});
    }
    cout << best_dist << '\n';
}           

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("infasuratoare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}