#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int ans = x;
    rep(i,n){
        if(s[i] == 'o') ans++;
        else if(s[i] == 'x' && ans > 0) ans--;
    }
    cout << ans << endl;
}
