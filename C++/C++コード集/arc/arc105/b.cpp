#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int min1 = a[0];
    int max1 = a[0];
    while(1){
        max1 = min1;
        rep(i,n){
            if(min1 != a[i]) a[i] %= min1;
            if(a[i] == 0) a[i] = min1;
            min1 = min(min1, a[i]);
        }
        if(max1 == min1){
            cout << min1 << endl;
            return 0;
        }
    }
}
