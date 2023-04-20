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
    ll n;
    cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    vl a2(n);
    rep(i,n){
        if(i == 0) a2[i] = a[i];
        else a2[i] = a2[i-1] + a[i];
    }
    ll ans = 0;
    for(ll i=0; i<n-1; i++){
        ans += a[n-1-i] * (n-1-i);
        ans -= a2[n-2-i];
    }
    cout << ans << endl;
}
