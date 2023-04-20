#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    while(x < y){
        if(x <= (double)b/(a-1)) {
            x *= a;
            if(x >= y) break;
            ans++;
        }
        else{
            ll kai = (y - x) / b;
            if(b * kai == y-x) kai--;
            x += b * kai;
            ans += kai;
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
