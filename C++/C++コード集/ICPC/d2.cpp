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
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());  //  まずソートする
    do{
        int cnt = 0;
        rep(i,n) b[i] = a[i];
        cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << "   ";
        int x = 0, y = 1, z = 2;
        while(1){
            int mn = min(b[x], min(b[y], b[z]));
            cnt += mn;
            b[x] -= mn;
            b[y] -= mn;
            b[z] -= mn;
            if(b[x] == 0) x
        }
        cout << cnt << endl;
    }while(next_permutation(a.begin(),a.end()));  //  次の順列にする。最後までいったら抜ける


}
