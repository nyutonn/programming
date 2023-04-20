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
    vi a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    set<int> ans;
    int min_num = a[0];
    ans.insert(min_num);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(gcd(a[i], a[j]) < min_num) ans.insert(gcd(a[i], a[j]));
        }
    }
    cout << ans.size() << endl;
}
