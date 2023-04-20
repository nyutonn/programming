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

ll myabs(ll a, ll b){
    if(a>b) return a-b;
    else return b-a;
}

ll mymin(ll a, ll b){
    if(a > b) return b;
    else return a;
}

int main(){
    int n;
    cin >> n;
    vl rgb(2*n);
    int ri = 0, gi = 0, bi = 0;
    string color = "";
    rep(i,2*n){
        ll a;
        char c;
        cin >> a >> c;
        color += c;
        if(c == 'R') {
            rgb[i] = a;
            ri ++;
        }
        if(c == 'G'){
            rgb[i] = a;
            gi ++;
        }
        if(c == 'B'){
            rgb[i] = a;
            bi ++;
        }
    }
    vl r(ri), g(gi), b(bi); 
    // rep(i,ri) cout << r[i] << endl;
    // rep(i,gi) cout << g[i] << endl;
    // rep(i,bi) cout << b[i] << endl;
    if(ri%2 == 0 && gi%2 == 0 && bi%2 == 0){
        cout << 0 << endl;
        return 0;
    }
    ri = 0; gi = 0; bi = 0;
    rep(i,2*n){
        if(color[i] == 'R') {
            r[ri] = rgb[i];
            ri ++;
        }
        if(color[i] == 'G'){
            g[gi] = rgb[i];
            gi ++;
        }
        if(color[i] == 'B'){
            b[bi] = rgb[i];
            bi ++;
        }
    }
    // cout << r[0] << b[0] << endl;
    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());
    // cout << r[0] << b[0] << endl;
    ll ans = 100000000000000000;
    if(ri%2 == 0){
        rep(i,gi){
            int left = -1, right = b.size();
            while(right - left > 1){
                int mid = (right + left) / 2;
                if(b[mid] > g[i]) right = mid;  
                else left = mid;
            }
            ans = mymin(ans, myabs(b[left], g[i]));
            ans = mymin(ans, myabs(b[left+1], g[i]));
        }
    }
    else if(gi%2 == 0){
        rep(i,bi){
            int left = -1, right = r.size();
            while(right - left > 1){
                int mid = (right + left) / 2;
                if(r[mid] > b[i]) right = mid;  
                else left = mid;
            }
            ans = mymin(ans, myabs(r[left], b[i]));
            ans = mymin(ans, myabs(r[left+1], b[i]));
            
        }
    } 
    else if(bi%2 == 0){
        rep(i,ri){
            int left = -1, right = g.size();
            while(right - left > 1){
                int mid = (right + left) / 2;
                if(g[mid] > r[i]) right = mid;  
                else left = mid;
            }
            ans = mymin(ans, myabs(g[left], r[i]));
            ans = mymin(ans, myabs(g[left+1], r[i]));
        }
    }
    cout << ans << endl;
}
