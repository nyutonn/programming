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
        ll n, s, k;
        cin >> n >> s >> k;
        bool ok = false;
        for(ll i=0; i<k; i++){
            ll ans = (n-s + n*i)/k;
            if(ans*k == (n-s + n*i)){
                cout << ans << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << -1 << endl;
    }
}
