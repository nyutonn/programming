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
    ll r, x, y;
    cin >> r >> x >> y;
    ll dist = x*x + y*y;
    if(dist == r*r) cout << 1 << endl;
    else if(dist < r*r) cout << 2 << endl;
    else{
        ll ans = 1;
        while(1){
            if(dist <= ans*ans*r*r){
                cout << ans << endl;
                return 0;
            }
            ans ++;
        }
    }
}
