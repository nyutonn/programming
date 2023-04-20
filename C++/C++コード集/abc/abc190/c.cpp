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

bool find(vector<int> vec, int number) {
  auto itr = find(vec.begin(), vec.end(), number);
  size_t index = distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
  }
  else { // 発見できなかったとき
    return false;
  }
}

int main(){
    int n, m, k;
    cin >> n >> m;
    vi a(m), b(m);
    rep(i,m) cin >> a[i] >> b[i];
    cin >> k;
    vi c(k), d(k);
    rep(i,k) cin >> c[i] >> d[i];
    int ans = 0;
    rep(tmp, 1<<k){
        int sum = 0;
        vi e(k);
        rep(i,k){
            if(tmp>>i&1) e[i] = b[i];
            else e[i] = a[i];
        }
        rep(i,m){
            if(find(e, a[i]) && find(e, b[i])) sum ++;
        }
        ans = max(sum, ans);
    }
    cout << ans << endl;
}
