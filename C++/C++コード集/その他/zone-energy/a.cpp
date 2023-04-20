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
    int cnt = 0;
    rep(i,9){
        if(s[i] == 'Z' && s[i+1] == 'O' && s[i+2] == 'N' && s[i+3] == 'e'){
            cnt ++;
        }
    }
    cout << cnt << endl;
}
