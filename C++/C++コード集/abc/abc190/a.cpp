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
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) cout << "Takahashi" << endl;
    else if(a < b) cout << "Aoki" << endl;
    else{
        if(c == 0) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
}
