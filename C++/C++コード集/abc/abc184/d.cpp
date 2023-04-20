#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    double dp[101][101][101] = {};
    // dpは期待値ではなく確率を足す
    
    dp[99][99][99] = 1;
    for(int a2=99; a2>=0; a2--){
        for(int b2=99; b2>=0; b2--){
            for(int c2=99; c2>=0; c2--){
                if(a2==99 && b2==99 && c2==99) continue;
                int sum = a2 + b2 + c2;
                dp[a2][b2][c2] =  (dp[a2+1][b2][c2] + 1) * ((double)a2)/sum
                                + (dp[a2][b2+1][c2] + 1) * ((double)b2)/sum
                                + (dp[a2][b2][c2+1] + 1) * ((double)c2)/sum;
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << dp[a][b][c] << endl;
}
