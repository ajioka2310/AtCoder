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
inline std::size_t max_line_width = 360;
inline std::size_t max_iteration_count = 40;

int max_depth=0;

void dfs(Graph &seen,const Graph &G,int x,int y,Graph &depth,int depth_now){
  cpp_dump(x,y);
  // 1次元目の最後の10要素、2次元目の最初の5要素と最後の5要素を表示します。
  // cpp_dump(depth);
  seen[y][x] = 1;
  cpp_dump(x,y);
  depth[y][x] = depth_now + 1;
  depth_now = depth[y][x];
  vec ls_idx = {-1,0,1};
  vec ls_idy = {-1,0,1};
  max_depth = max(max_depth,depth[y][x]);
  for (auto idy: ls_idy){
    for (auto idx: ls_idx){
      if ((idx==0&&idy!=0)||(idx!=0&&idy==0)){
        // cpp_dump(idx,idy);
        if (seen[y+idy][x+idx]||G[y+idy][x+idx]==0) continue;
        dfs(seen, G, x+idx, y+idy, depth, depth_now);
      }
    }
  }
  seen[y][x] = 0;

}

Graph create_seen(int m,int n){
  Graph seen(n+2,vec(m+2,0));
  rep(i,n+2){
    rep(j,m+2){
      if (i==0 || j==0 || i==n+1 || j==m+1){
        seen[i][j] = 1;
      }
    }
  }
  return seen;
} 

int main(){
  // input
  int m,n; cin >> m >> n;
  Graph graph;
  rep(i,n+2) {
    vec ls(m+2,0);
    graph.push_back(ls);
  }
  krep(i,1,n+1){
    krep(j,1,m+1){
      cin >> graph[i][j];
    }
  }

  cpp_dump(graph);

  krep(i,1,n+1){
    krep(j,1,m+1){
      if (graph[i][j]==1){
        // cpp_dump(i,j);
        Graph seen = create_seen(m,n);
        Graph depth = create_seen(m,n);
        dfs(seen,graph,j,i,depth,0);
        cpp_dump(i,j,max_depth,depth);
      }


    }
  }

  cout << max_depth << endl;

}