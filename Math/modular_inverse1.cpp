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

int gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0){
    int g = gcd(a, b, x0, y0);
    if(c % g)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if(a < 0)
        x0 = -x0;
    if(b < 0)
        y0 = -y0;
    return true;
}

void solve(){
    int a, m, x, y;
    cin >> a >> m;
    find_any_solution(a, m, 1, x, y);
    x = (x + m) % m;
    cout << x << '\n'; 
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