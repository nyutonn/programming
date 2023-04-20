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

int main(){
    int t;
    cin >> t;
    rep(i,t){
        ll l, r;
        cin >> l >> r;
        ll n = r - 2*l + 1;
        if(n < 0) n = 0;
        ll ans = n*(n+1)/2;
        cout << ans << endl;
    }
}
