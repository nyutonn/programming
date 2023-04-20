#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n, w;
    cin >> n >> w;
    vl s(n), t(n), p(n);
    rep(i,n) cin >> s[i] >> t[i] >> p[i];
    vl v(200005);
    rep(i,n){
        v[s[i]] += p[i];
        v[t[i]] -= p[i];
    }
    rep(i,200004) v[i+1] += v[i];
    rep(i,200004){
        if(v[i] > w){
             cout << "No" << endl; 
             return 0;
        }
    }
    cout << "Yes" << endl;
}
