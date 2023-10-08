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

struct Trie {
    int cnt, nrchildren;
    Trie *child[26];
    Trie(){
        cnt = nrchildren = 0;
        memset(child, 0, sizeof(child));
    }
};

Trie *T = new Trie;

void ins(Trie *node, char *s){
    if(*s == '\n'){
        node->cnt++;
        return;
    }
    if(node->child[*s-97] == 0){
        node->child[*s-97] = new Trie;
        node->nrchildren++;
    }
    ins(node->child[*s-97], s+1);
}

int del(Trie *node, char *s){
    if(*s == '\n')
        node->cnt--;
    else if(del(node->child[*s-97], s+1)){
        node->child[*s-97] = 0;
        node->nrchildren--;
    }
    if(node->nrchildren == 0 && node->cnt == 0 && node != T){
        delete node;
        return 1;
    }
    return 0;
}

int cnt(Trie *node, char *s){
    if(*s == '\n')
        return node->cnt;
    if(node->child[*s-97])
        return cnt(node->child[*s-97], s+1);
    return 0;
}

int prefix(Trie *node, char *s, int k){
    if(*s == '\n' || node->child[*s-97] == 0)
        return k;
    return prefix(node->child[*s-97], s+1, k+1);
}

void solve(){
    string s;
    while(getline(cin, s)){
        //cout << s << "A\n";
        int t = s[0] - 48;
        string cuv = string(s.begin()+2, s.end());
        char str[cuv.size()+1];
        for(int i = 0; i < cuv.size(); i++)
            str[i] = cuv[i];
        str[cuv.size()] = '\n';
        //cout << str << '\n';
        //0 add str in lista
        //1 delete str din lista
        //2 str cnt din lista
        //3 cel mai lung prefix comun str cu orice alt cuv
        switch(t){
        case 0: ins(T, str); break;
        case 1: del(T, str); break;
        case 2: cout << cnt(T, str) << '\n'; break;
        case 3: cout << prefix(T, str, 0) << '\n'; break;
        }
    }
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