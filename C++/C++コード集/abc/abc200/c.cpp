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
    int n;
    cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    vl amari(200);
    rep(i,n){
        amari[a[i]%200] ++;
    }
    ll ans = 0;
    rep(i,200){
        ans += amari[i]*(amari[i]-1)/2;
    }
    cout << ans << endl;
}
