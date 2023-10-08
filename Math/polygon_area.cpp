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

struct pt{
    ll x, y;
};
 
void solve(){
    int n;
    cin >> n;
    vector<pt> points(n);
    for(int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    points.pb(points[0]);
    ll area = 0;
    for(int i = 1; i <= n; i++){
        pt p = points[i];
        pt q = points[i-1];
        area += (p.x - q.x) * (p.y + q.y);
    }  
    //actual area ii area / 2;
    cout << abs(area) << '\n';
}   
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}