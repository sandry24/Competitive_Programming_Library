#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

ll ans = 0;

vi build_lps(string s){
    int n = s.size();
    vi lps(n);
    for(int i = 1; i < n; i++){
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j])
            j = lps[j-1];
        if(s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

void KMP(string p, string s){
    int n = s.size();
    int m = p.size();
    vi lps = build_lps(p);
    int i = 0, j = 0;
    while(i < n){
        if(p[j] == s[i]){
            i++;
            j++;
        }
        if(j == m){
            ans++;
            j = lps[j-1];
        } else if(i < n && p[j] != s[i]){
            if(j == 0)
                i++;
            else
                j = lps[j-1];
        }
    }
}
 
void solve(){
    string s, p;
    cin >> s >> p;
    KMP(p, s);
    cout << ans << '\n';
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