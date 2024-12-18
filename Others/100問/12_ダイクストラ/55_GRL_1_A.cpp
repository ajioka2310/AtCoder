#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define pair_int pair<int,int>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
const int INF=INT32_MAX/2;
const int MOD=10007;

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;
struct edge{
  int to;
  int cost;
};

int main(){
  int V,E,r;cin>>V>>E>>r;
  vector<vector<edge>> graph(V);
  rep(i,5){
    int s,t,d;cin>>s>>t>>d;
    edge now;
    now.to = t;
    now.cost = d;
    graph[s].push_back(now);
  }
  // cpp_dump(graph);
  vec dist(V,INF);
  priority_queue<pair_int,vector<pair_int>,greater<pair_int>> que;
  dist[0] = 0;
  que.push({0,r});
  while(!que.empty()){
    // 現在の座標と距離を求める
    pair_int now = que.top();
    int distance = now.first;
    int idx = now.second;
    que.pop();
    // // これがないと無限ループになる
    // if (distance>dist[idx]) continue;
    // 到達可能な節を見つける
    rep(i,graph[idx].size()){
      int to = graph[idx][i].to;
      int cost = graph[idx][i].cost;
      // 今いる節までの最短距離+移動コスト < 既存の到達最小コスト
      if (distance+cost < dist[to]){
        dist[to] = distance + cost;
        que.push({dist[to],to});
      }
    }
    // cpp_dump(que);
  }
  // cpp_dump(dist);
  rep(i,V){
    cout << dist[i] << endl;
  }
}
