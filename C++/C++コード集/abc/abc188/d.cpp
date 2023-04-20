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
    ll n, m;
    cin >> n >> m;
    vl tasu(1000000005), hiku(1000000005);
    rep(i,n){
        ll a, b, c;
        cin >> a >> b >> c;
        tasu[a] += c;
        hiku[b] += c;
    
}
