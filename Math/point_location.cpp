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

//Bx * Cy - By * Cx, punctul A ca centru 
//daca cross product e pozitiv, unghiul dintre B si C este pozitiv
// => punctul C se afla in stanga dreptei A B
//daca e negativ, se afla in dreapta, si daca == 0 inseamna ca A B si C sunt pe aceeasi dreapta
ll cross(pt a, pt b, pt c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
void solve(){
    pt a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ll ans = cross(a, b, c);
    if(ans == 0)
        cout << "TOUCH\n";
    else if(ans > 0)
        cout << "LEFT\n";
    else
        cout << "RIGHT\n";
}   
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}