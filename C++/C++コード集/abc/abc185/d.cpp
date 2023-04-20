#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n, m;
    cin >> n >> m;
    vi a(m+2);
    rep(i,m) {
        cin >> a[i+1];
    }
    a[m+1] = n+1;
    sort(a.begin(),a.end());
    int cnt = 1000000000;
    rep(i,m+1){
        if(a[i+1] - a[i] == 1) continue;
        else cnt = min(cnt, a[i+1] - a[i] -1); 
    }
    // cout << cnt << endl;
    int ans = 0;
    // rep(i,m+2) cout << a[i] << endl;
    rep(i,m+1){
        if(a[i+1] - a[i] == 1) continue;
        int dif = a[i+1] - a[i] - 1;
        ans += (dif+cnt-1)/cnt;
        // cout << ans << endl;
    }
    cout << ans << endl;
}
