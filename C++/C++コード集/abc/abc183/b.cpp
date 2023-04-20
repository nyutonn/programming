#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    double ans;
    if(gx >= sx) ans = gx - (abs(gx-sx) * abs(gy) / abs(sy+gy));
    else ans = gx + (abs(gx-sx) * abs(gy) / abs(sy+gy));
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
