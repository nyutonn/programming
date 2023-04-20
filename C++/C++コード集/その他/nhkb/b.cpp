#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h)rep(j,w-1){
        if(s[i][j] == '.' && s[i][j+1] == '.') ans ++;
    }
    rep(j,w)rep(i,h-1){
        if(s[i][j] == '.' && s[i+1][j] == '.') ans ++;
    }
    cout << ans << endl;
}
