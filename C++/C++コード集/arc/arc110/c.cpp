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
    if(t == "1"){
        cout << 20000000000 << endl;
        return 0;
    }
    if(t == "11" || t == "10" || t == "0"){
        cout << 10000000000 << endl;
        return 0;
    }
    int first = -1, last = 0, cnt = 0;
    rep(i,n){
        if(first == -1){
            if(t[0] == '0') first = 1;
            else if(t[0] == '1' && t[1] == '0') {
                first = 2;
                i++;
            }
            else if(t[0] == '1' && t[1] == '1' && t[2] == '0'){
                first = 0;
                cnt++;
                i += 2;
            }
            else{
                cout << 0 << endl;
                return 0;
            }
        }
        else if(t[i] == '1' && t[i+1] == '1' && t[i+2] == '0'){
            cnt++;
            i += 2;
        }
        else{
            if(n-i == 2 && t[i] == '1' && t[i+1] == '1') last = 2;
            else if(n-i == 1 && t[i] == '1') last = 1;
            else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    ll minus;
    if(first > 0 && last > 0) minus = 1;
    else if(first == 0 && last == 0) minus = -1;
    else if(first*last == 0) minus = 0;
    else minus = 1;
    ll ans = 10000000000 - minus - cnt;
    // cout << minus << endl;
    // cout << cnt << endl;
    cout << ans << endl;
}
