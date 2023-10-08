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

int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    return 0;
}

int apply_op(int a, int b, char op){
    switch(op){
    case '+': return a+b; break;
    case '-': return a-b; break;
    case '*': return a*b; break;
    case '/': return a/b; break;
    }
}

int evaluate(string tokens){
    stack<int> values;
    stack<char> ops;
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] == '('){
            ops.push(tokens[i]);
        } else if(isdigit(tokens[i])){
            int val = 0;
            while(i < tokens.size() && isdigit(tokens[i])){
                val = val * 10 + (tokens[i] - 48);
                i++;
            }
            values.push(val);
            i--;
        } else if(tokens[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                int op = ops.top(); ops.pop();
                values.push(apply_op(val1, val2, op));
            }
            if(!ops.empty())
                ops.pop();
        } else {
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                int op = ops.top(); ops.pop();
                values.push(apply_op(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while(!ops.empty()){
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        int op = ops.top(); ops.pop();
        values.push(apply_op(val1, val2, op));
    }
    return values.top();
}

void solve(){
    string s;
    cin >> s;
    cout << evaluate(s) << '\n';
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