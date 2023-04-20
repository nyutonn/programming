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

ll bai (bool ok, string h, ll a, string *p, ll n){
    if(ok && h == "AND"){
        if(a == 1) return 1;
        return bai(true, p[a-2], a-1, p, n);
    }
    else if(!ok && h == "AND"){
        if(a == 1) return 3;
        return bai(true, p[a-2], a-1, p, n) + 2*bai(false, p[a-2], a-1, p, n);
    }
    else if(ok && h == "OR"){
        if(a == 1) return 3;
        return 2*bai(true, p[a-2], a-1, p, n) + bai(false, p[a-2], a-1, p, n);
    }
    else{
        if(a == 1) return 1;
        return bai(false, p[a-2], a-1, p, n);
    }
}

int main(){
    ll n;
    // vector<string> s(n);
    cin >> n;
    string s[n+1];
    rep(i,n) cin >> s[i];
    
    ll ans = bai(true, s[n-1], n, s, n);
    cout << ans << endl;
}
