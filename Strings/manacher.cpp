#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
 
vi manacher_odd(string &s){
    int n = s.size();
    s = "$" + s + "^";
    vi p(n+2);
    int l = 0, r = -1;
    for(int i = 1; i <= n; i++){
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if(p[i] + i > r){
            r = p[i] + i;
            l = i - p[i];
        }
    }
    return vi(p.begin()+1, p.end()-1);
}
 
vi manacher(string &s){
    string t = "";
    for(auto i : s)
        t += string("#") + i;
    t += "#";
    return manacher_odd(t);
}
 
void solve(){
    string s;
    cin >> s;
    vi d = manacher(s), d1(s.size()), d2(s.size());
    for(int i = 0; i < s.size(); i++){
        d1[i] = d[2*i+1]/2;
        d2[i] = (d[2*i] - 1)/2;
    }
    for(auto i : d1)
        cout << i << ' ';
    cout << '\n';
    for(auto i : d2)
        cout << i << ' ';
    cout << '\n';
    int maxe_imp = *max_element(d1.begin(), d1.end()), maxe_p = *max_element(d2.begin(), d2.end());
    int max_index, par = 0, offset;
    if(maxe_imp*2-1 > maxe_p*2){
        int pos = find(d1.begin(), d1.end(), maxe_imp) - d1.begin();
        max_index = pos;
        par = 0;
        offset = d1[pos];
    } else {
        int pos = find(d2.begin(), d2.end(), maxe_p) - d2.begin();
        max_index = pos;
        par = 1;
        offset = d2[pos];
    }
    string max_pal = "";
    int start = max_index - (offset - 1);
    if(par)
        start--;
    for(int i = start; i < max_index + offset; i++)
        max_pal += s[i];
    cout << max_pal << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}