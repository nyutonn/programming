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
    string s;
    cin >> s;
    string t = "";
    int n = s.size();
    rep(i,n){
        if(s[i] == 'R') reverse(t.begin(),t.end());
        else t += s[i];
        // cout << t << endl;
    }
    string ans;
    int mozi = 0;
    int n2 = t.size();
    // cout << t << endl;
    for(int i=0; i<n2; i++){
        if(mozi > 0 && t[i] == ans[mozi-1]) mozi --;
        else{
            ans[mozi] = t[i];
            mozi ++;
        }
        // rep(j,mozi) cout << ans[j];
        // cout << endl;
    }
    rep(i,mozi) cout << ans[i];
    cout << endl;
}