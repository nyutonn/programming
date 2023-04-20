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
    string t;
    cin >> n >> t;
    ll cnt = 0;
    rep(i,n-2){
        if(t[i] == '1' && t[i+1] == '1' && t[i+2] == '0') cnt++;
    }
    if(n/3 - 1 > cnt){
        cout << 0 << endl;
        return 0;
    }
    if(n - cnt*3 >= 4) cnt ++;
    cout << 10000000000 - cnt << endl;
}
