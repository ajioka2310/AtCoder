#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>

#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;

vec seen;

void dfs(const Graph &G, vec &points,int node, int last_node){
  seen[node] = 1;
  points[node] += points[last_node];
  for (auto next_v: G[node]){
    if (seen[next_v]) continue;
    dfs(G, points, next_v, node);
  }
}


int main(){
  // input
  int N,Q; cin >> N >> Q;
  Graph graph(N+1);
  rep(i,N-1){
    int a,b;cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  rep(i,N+1){
    sort(all(graph[i]));
  }
  // cpp_dump(graph);
  
  vec points(N+1,0);
  // cpp_dump(points);



  rep(i,Q){
    int p,x; cin >> p >> x;
    // cpp_dump(p,x);
    points[p] += x;
  }

  // cpp_dump(points);

  // init
  seen.assign(N+1,0);
  seen[0] = 1;

  // dfs
  int last_node = 0;
  int node = 1;
  dfs(graph, points, node, last_node);

  // cpp_dump(points);
  krep(i,1,N+1){
    cout << points[i] << " ";
  }
  cout << endl;

}