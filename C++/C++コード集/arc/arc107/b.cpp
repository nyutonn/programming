#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll n, k;
    cin >> n >> k;
    k = abs(k);
    ll mn = 2;
    ll mx = 2*n;
    ll mid = n+1;
    ll gyou = 2*n - k - 1;
    ll ans = 0;
    ll left = 1;
    ll right = n - abs(mid - (2*n-k));
    bool lok = true;
    bool rok = true;
    if (n > k){
        rep(i,gyou){
            ans += left*right;
            if(left < n && lok) left++;
            else {
                left --;
                lok = false;
            }
            if(right < n && rok) right++;
            else {
                right--;
                rok = false;
            }
        }
    }
    else{
        rep(i,gyou){
            ans += left*right;
            left++;
            right--;
        }
    }
    cout << ans << endl;
}
