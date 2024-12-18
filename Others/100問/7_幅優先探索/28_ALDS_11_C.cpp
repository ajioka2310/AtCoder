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

#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
namespace cp = cpp_dump;


int main(){
  // input
  int N; cin >>N;
  Graph graph(N+1);
  krep(i,1,N+1){
    int u,k; cin >> u >>k;
    rep(j,k){
      cpp_dump(i,j,k);
      int v; cin >>v;
      graph[i].push_back(v);

    }
  }
  vec seen(N+1,0);
  vec dist(N+1,-1);
  queue<int> que;
  
  cpp_dump(graph);
  seen[1] = 1;
  dist[1] = 0;
  que.push(1);
  while (!que.empty())
  { 
    cpp_dump(que);
    int v = que.front();
    que.pop();
    for (int next: graph[v]){
      if (seen[next]==1) continue;
      seen[next] = 1;
      dist[next] = dist[v] + 1;
      que.push(next);
    }
  }
  krep(i,1,N+1){
    cout << i << " " << dist[i] << endl;
  }

  
}