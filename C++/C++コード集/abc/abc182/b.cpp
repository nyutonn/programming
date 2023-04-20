#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    vi igcd(1005);
    for(int i = 2; i<1001; i++){
        bool ok = true;
        rep(j,n){
            if(a[j]%i == 0) igcd[i]++;
        }
    }
    int ans = 0;
    rep(i,1005){
        if(igcd[ans] < igcd[i]) ans = i;
    }
    cout << ans << endl;
    // rep(i,10) cout << igcd[i] << endl;
}
