#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    vi a(4);
    rep(i,4) cin >> a[i];
    sort(a.begin(),a.end());
    int sum = 0;
    rep(i,4) sum += a[i];
    int half = a[0] + a[1];
    if(half * 2 == sum){
        cout << "Yes" << endl;
        return 0;
    }
    half += a[2];
    if(half * 2 == sum){
        cout << "Yes" << endl;
        return 0;
    }
    half -= a[2];
    half -= a[1];
    half += a[3];
    if(half * 2 == sum){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
