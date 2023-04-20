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
    ll b, c;
    cin >> b >> c;
    ll ans = 1;
    if(b != 0 && c == 1){
        ans = 2;
    }
    else if(b > 0 && c < 2*b){
        ans += c-1;
        if(c%2 != 0) ans --;
        ans += c;
        if(c%2 == 0) ans--; 
    }
    else if(b > 0){
        ans += (b-1)*2;
        ans += 1;
        ans += c-1;
        // if(c%2 != 0) ans --;
    }
    else if(b == 0){
        ans += c-1;
    }
    else{
        ans += c;
        //if(c%2 == 0) ans --;
        ans += min((b*(-1)-1)*2+1, (c-1)/2);
    }
    cout << ans << endl;
}
