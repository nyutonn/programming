#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vvi light(h, vi(w));
    vvi block(h, vi(w));
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        light[a][b] = 1;
    }
    rep(i,m){
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        block[c][d]++;
    }
    vvi akari(h, vi(w));

    rep(i,h)rep(j,w){
        bool ok = true;
        if(light[i][j] == 1) akari[i][j] = 1;
        if(block[i][j] == 1) continue;
        int up = i;
        rep(k,h){
            up --;
            if(up < 0) break;
            if(block[up][j] == 1) break;
            if(light[up][j] == 1) {
                ok = false;
                akari[i][j] = 1;
                break;
            }
        }
        if(!ok) continue;
        int down = i;
        rep(k,h){
            down++;
            if(down >= h) break;
            if(block[down][j] == 1) break;
            if(light[down][j] == 1) {
                ok = false;
                akari[i][j] = 1;
                break;
            }
        }
        if(!ok) continue;
        int right = j;
        rep(k,w){
            right++;
            if(right >= w) break;
            if(block[i][right] == 1) break;
            if(light[i][right] == 1) {
                ok = false;
                akari[i][j] = 1;
                break;
            }
        }
        if(!ok) continue;
        int left = j;
        rep(k,w){
            left--;
            if(left < 0) break;
            if(block[i][left] == 1) break;
            if(light[i][left] == 1) {
                ok = false;
                akari[i][j] = 1;
                break;
            }
        }
    }
    int ans = 0;
    rep(i,h)rep(j,w) if(akari[i][j] == 1) ans++;
    cout << ans << endl;
}
