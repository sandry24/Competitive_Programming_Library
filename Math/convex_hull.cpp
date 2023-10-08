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
    double x, y;
};
 
int n;
vector<pt> a(200001);
 
double cross(pt a, pt b, pt c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
vector<pt> convex_hull(){
    vector<pt> s;
    s.pb(a[0]);
    s.pb(a[1]);
    for(int i = 2; i < n; i++){
        while(s.size() >= 2 && cross(s[s.size()-2], s[s.size()-1], a[i]) < 0)
            s.pop_back();
        s.push_back(a[i]);
    }
    return s;
}
 
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.begin()+n, [](pt a, pt b){return mp(a.x, a.y) < mp(b.x, b.y);});
    vector<pt> c1 = convex_hull(); // lower
    reverse(a.begin(), a.begin()+n);
    vector<pt> c2 = convex_hull(); // upper
    cout << c1.size() + c2.size() - 2 << '\n';
    for(int i = 0; i < c1.size(); i++)
        cout << setprecision(12) << c1[i].x << ' ' << c1[i].y << '\n';
    for(int i = 1; i < c2.size()-1; i++)
        cout << setprecision(12) << c2[i].x << ' ' << c2[i].y << '\n';
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