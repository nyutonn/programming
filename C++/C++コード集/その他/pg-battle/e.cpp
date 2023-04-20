#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> first_order; // 行きがけ順
vector<int> last_order; // 帰りがけ順

void dfs(const Graph &G, int v, int& first_ptr, int& last_ptr) {
    // 行きがけ順をインクリメントしながらメモ
    first_order[v] = first_ptr++;

    seen[v] = true; 
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v, first_ptr, last_ptr);
    }

    // 帰りがけ順をインクリメントしながらメモ
    last_order[v] = last_ptr++;
}

int main() {

    

    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    first_order.resize(N);
    last_order.resize(N);
    int first_ptr = 0, last_ptr = 0;
    dfs(G, 0, first_ptr, last_ptr);

    // 各頂点 v の行きがけ順、帰りがけ順を出力
    for (int v = 0; v < N; ++v){}
        cout << v << ": " << first_order[v] << ", " << last_order[v] << endl;
    }
}