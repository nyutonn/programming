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
    vector<char> t2(750000);
    int front = 250000-1, end = 250000;
    int n = s.size();
    bool ok = true;
    rep(i,n){
        if(s[i] == 'R' && ok) ok = false;
        else if(s[i] == 'R' && !ok) ok = true;
        else if(ok){
            t2[end] = s[i];
            end ++;
        }
        else{
            t2[front] = s[i];
            front --;
        }
    }
    vector<char> t(500000);
    bool a = false;
    rep(i,250000){
        if(a) break;
        if(t2[i] != 0){
            rep(j,500000){
                t[j] = t2[i+j];
            }
            a = true;
            break;
        }
    }

    rep(i,n) cout << t[i];
    cout << endl;

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
    // reverse(ans.begin(),ans.end());
    mozi --;
    cout << mozi << endl;
    rep(i,mozi) cout << ans[mozi-i];
    cout << endl;
}