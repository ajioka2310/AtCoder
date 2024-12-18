#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// 型定義（可読性のため）
using i64 = long long;
using Edge = pair<int, i64>; // (行き先ノード, コスト)
using Graph = vector<vector<Edge>>; // グラフの隣接リスト表現

// ダイクストラ法の関数
void Dijkstra(const Graph& graph, vector<i64>& distances, int startIndex, vector<int>& path) {
    // 優先度付きキュー（最小ヒープ）
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;

    // 始点の初期設定
    distances[startIndex] = 0; // 始点の距離は0
    pq.emplace(0, startIndex); // 優先度付きキューに(距離, ノード)を挿入

    while (!pq.empty()) {
        // キューから現在のノードを取り出す
        auto [currentDistance, currentNode] = pq.top();
        pq.pop();

        // 枝刈り: 既知の最短距離よりも大きい場合は無視
        if (distances[currentNode] < currentDistance) continue;

        // 隣接ノードを調べる
        for (const auto& edge : graph[currentNode]) {
            int nextNode = edge.first;
            i64 edgeCost = edge.second;
            i64 newDistance = currentDistance + edgeCost;

            // 最短距離を更新する場合
            if (newDistance < distances[nextNode]) {
                distances[nextNode] = newDistance; // 距離を更新
                path[nextNode] = currentNode;     // 経路を記録
                pq.emplace(newDistance, nextNode); // 更新されたノードをキューに追加
            }
        }
    }
}

int main() {
    // 入力: グラフの構築
    int n = 5; // ノード数
    Graph graph(n);
    graph[0].emplace_back(1, 2); // ノード0 → ノード1 (コスト2)
    graph[0].emplace_back(2, 4); // ノード0 → ノード2 (コスト4)
    graph[1].emplace_back(2, 1); // ノード1 → ノード2 (コスト1)
    graph[1].emplace_back(3, 7); // ノード1 → ノード3 (コスト7)
    graph[2].emplace_back(4, 3); // ノード2 → ノード4 (コスト3)
    graph[3].emplace_back(4, 1); // ノード3 → ノード4 (コスト1)

    // 始点ノード
    int start = 0;

    // 結果を保存する配列
    vector<i64> distances(n, numeric_limits<i64>::max()); // 初期値は∞
    vector<int> path(n, -1); // 経路記録（前のノードを保存）

    // ダイクストラ法の実行
    Dijkstra(graph, distances, start, path);

    // 結果の出力
    cout << "Node\tDistance from Start\tPath" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << distances[i] << "\t\t";
        int p = i;
        while (p != -1) {
            cout << p << " ";
            p = path[p];
        }
        cout << endl;
    }

    return 0;
}
