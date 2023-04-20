#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    ll n;
    cin >> n;
    priority_queue<ll> q;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            q.push(-i);
            q.push(-n/i);
        }
    }
    while(!q.empty()){
        cout << -q.top() << endl;
        q.pop();
        if(q.top()*q.top() == n) q.pop();
    }
}
