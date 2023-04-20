#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
// #include <atcoder/all>
// using namespace atcoder;

ll bai (ll a, string *p){
    if(a==0) return 1;
    if(p[a-1] == "AND") return bai(a-1, p);
    else return pow(2,a) + bai(a-1, p);
}

int main(){
    ll n;
    // vector<string> s(n);
    cin >> n;
    string s[n+1];
    rep(i,n) cin >> s[i];
    
    ll ans = bai(n, s);
    cout << ans << endl;
}
