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
    vl a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int cnt = 0;
    rep(i,n) cnt += a[i]*b[i];
    if(cnt == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
