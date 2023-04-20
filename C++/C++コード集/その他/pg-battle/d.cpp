#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> graph(n);  //  頂点が０からではないときはn+1とする
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);  //  有向グラフを作る
    }
    vector<int> dist(n, -1);  //  距離を-1で初期化、頂点が０からでないならn+1とする
    queue<int> que;
    dist[0] = 0;  //  スタートの頂点の距離を0にする
    que.push(0);  //  スタートの頂点をqueに突っ込む
    vi ans(n);
    ans[0] = 1;
    while(!que.empty()){  //  全ての頂点が訪問済なら終了
        int v = que.front();  //  先頭のqueを調べる
        que.pop();  //  先頭のqueを消す
        for(int nv : graph[v]){  //  頂点に隣接している全ての頂点を取り出す
            if(dist[nv] != -1) continue;  //  訪問済なら打ち切る
            dist[nv] = dist[v] + 1;  //  隣接している方が1遠いはず
            que.push(nv);  //  次に調べるためにqueに突っ込む
        }
    }   
    
    rep(i,n) cout << dist[i] << endl;
    return 0;
}
