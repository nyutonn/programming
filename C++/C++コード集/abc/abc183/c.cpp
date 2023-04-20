#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll n, k;
    cin >> n >> k;
    vvl t(n, vl(n));
    rep(i,n)rep(j,n) cin >> t[i][j];
    ll ans = 0;
    vl v(n-1);
    rep(i,n-1) v[i] = i+1;
    do{
        ll sum = 0;
        rep(i,n){
            if(i==0) sum += t[0][v[i]];
            else if(i == n-1) sum += t[v[i-1]][0];
            else sum += t[v[i-1]][v[i]];
            if(sum == k) ans ++;
        }
    }while(next_permutation(v.begin(),v.end()));

    cout << ans << endl;
}
