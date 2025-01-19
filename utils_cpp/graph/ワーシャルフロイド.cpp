#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;

/* warshall_floyd(dist)
    入力：初期化した dist
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納
*/
void warshall_floyd(vector<vector<long long>> &dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

vector<vector<long long>> dist = {{0, 5, -1, INF},
                                  {INF, 0, INF, 3},
                                  {INF, INF, 0, 1},
                                  {INF, INF, 4, 0}};
int main() {
    int V = (int)dist.size();  // 頂点数
    warshall_floyd(dist);      // 更新
    return 0;
}