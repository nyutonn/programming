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
    vi x(n), y(n);
    bool ok = false;
    rep(i,n) cin >> x[i] >> y[i];
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int yoko1 = x[j] - x[i];
                int tate1 = y[j] - y[i];
                int yoko2 = x[k] - x[j];
                int tate2 = y[k] - y[j];
                // if(yoko1 == 0 && tate2 == 0) ok = true;
                // else if(yoko2 == 0 && tate1 == 0) ok = true;
                // else if(tate1 == 0 || tate2 == 0 || yoko1 == 0 || yoko2 == 0) continue;
                if(tate1*yoko2 - tate2*yoko1 == 0) ok = true;
                else continue;
            }
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
