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
    vector<char> ans(3);
    ans[0] = s[1];
    ans[1] = s[2];
    ans[2] = s[0];
    cout << ans[0] << ans[1] << ans[2] << endl;
}
