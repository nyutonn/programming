#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    vi x(100), y(100);
    rep(i,100) cin >> x[i] >> y[i];
    string ans = "";
    int nx = 0, ny = 0;
    for(int i=0; i<100; i++){
        // while(1){
            bool have = false;
            int nx2 = nx, ny2 = ny;
            
            if(x[i] > nx){
                for(int j=0; j < x[i] - nx2; j++){
                    if(i != 99 && nx == x[i+1] && ny == y[i+1]){
                        bool ok2 = false;
                        for(int j=1; j <= abs(ny - y[i]); j++){
                            if(ny > y[i] && ny < y[i] + j) break;
                            if(ny < y[i] && ny > y[i] - j) break;
                            bool ok = true;
                            for(int k=0; k<100; k++){
                                if(y[i] - j == y[k] && x[i] == x[k] && ny < y[i]) ok = false;
                                if(y[i] + j == y[k] && x[i] == x[k] && ny > y[i]) ok = false;
                            }
                            if(ok) {
                                ok2 = true;
                                x[i+1] = x[i];
                                if(ny < y[i]) y[i+1] = y[i] - j;
                                else y[i+1] = y[i] + j;
                                break;
                            }
                            else ok = true;
                        }
                        if(ok2) {
                            ans += "I";
                            have = true;
                        }
                    }

                    if(have == true && nx == x[i+1]){
                        ans += "O";
                        have = false;
                    }

                    ans += "D";
                    nx++;
                }
            }


            if(x[i] < nx){
                for(int j=0; j < nx2 - x[i]; j++){
                    if(i != 99 && nx == x[i+1] && ny == y[i+1]){
                        bool ok2 = false;
                        for(int j=1; j <= abs(ny - y[i]); j++){
                            if(ny > y[i] && ny < y[i] + j) break;
                            if(ny < y[i] && ny > y[i] - j) break;
                            bool ok = true;
                            for(int k=0; k<100; k++){
                                if(y[i] - j == y[k] && x[i] == x[k] && ny < y[i]) ok = false;
                                if(y[i] + j == y[k] && x[i] == x[k] && ny > y[i]) ok = false;
                            }
                            if(ok) {
                                ok2 = true;
                                x[i+1] = x[i];
                                if(ny < y[i]) y[i+1] = y[i] - j;
                                else y[i+1] = y[i] + j;
                                break;
                            }
                            else ok = true;
                        }
                        if(ok2) {
                            ans += "I";
                            have = true;
                        }
                    }

                    if(have == true && nx == x[i+1]){
                        ans += "O";
                        have = false;
                    }

                    ans += "U";
                    nx--;
                }
            }


            if(y[i] > ny){
                for(int j=0; j < y[i] - ny2; j++){
                    if(i != 99 && nx == x[i+1] && ny == y[i+1]){
                        // cout << 1000000000000 << endl;
                        bool ok2 = false;
                        for(int j=1; j <= abs(ny - y[i]); j++){
                            if(ny > y[i] && ny < y[i] + j) break;
                            if(ny < y[i] && ny > y[i] - j) break;
                            bool ok = true;
                            for(int k=0; k<100; k++){
                                if(y[i] - j == y[k] && x[i] == x[k] && ny < y[i]) ok = false;
                                if(y[i] + j == y[k] && x[i] == x[k] && ny > y[i]) ok = false;
                            }
                            if(ok) {
                                ok2 = true;
                                x[i+1] = x[i];
                                if(ny < y[i]) y[i+1] = y[i] - j;
                                else y[i+1] = y[i] + j;
                                break;
                            }
                            else ok = true;
                        }
                        if(ok2) {
                            ans += "I";
                            have = true;
                        }
                    }

                    if(have == true && ny == y[i+1]) {
                        ans += "O";
                        have = false;
                    }

                    ans += "R";
                    ny ++;
                }
            }


            if(y[i] < ny){
                for(int j=0; j < ny2 - y[i]; j++){
                    if(i != 99 && nx == x[i+1] && ny == y[i+1]){
                        bool ok2 = false;
                        for(int j=1; j <= abs(ny - y[i]); j++){
                            if(ny > y[i] && ny < y[i] + j) break;
                            if(ny < y[i] && ny > y[i] - j) break;
                            bool ok = true;
                            for(int k=0; k<100; k++){
                                if(y[i] - j == y[k] && x[i] == x[k] && ny < y[i]) ok = false;
                                if(y[i] + j == y[k] && x[i] == x[k] && ny > y[i]) ok = false;
                            }
                            if(ok) {
                                ok2 = true;
                                x[i+1] = x[i];
                                if(ny < y[i]) y[i+1] = y[i] - j;
                                else y[i+1] = y[i] + j;
                                break;
                            }
                            else ok = true;
                        }
                        if(ok2) {
                            ans += "I";
                            have = true;
                        }
                    }

                    if(have == true && ny == y[i+1]) {
                        ans += "O";
                        have = false;
                    }

                    ans += "L";
                    ny--;
                }
            }


            if(nx == x[i] && ny == y[i]) {
                x[i] = -1;
                y[i] = -1;
                // break;
            }
        // }
        
        ans += "I";
    }
    cout << ans << endl;
}
