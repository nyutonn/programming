#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ans += (b+a)*(b-a+1)/2;
    }
    cout << ans << endl;
}
