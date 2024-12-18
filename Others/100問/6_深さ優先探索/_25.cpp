#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>

#define graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;

vec seen;
vec first_order;
vec last_order;

void dfs(const graph &G, int node, int& stamp){
  // cpp_dump(G);
  // cpp_dump(seen);
  // cpp_dump(node);
  first_order[node] = stamp++;
  seen[node] = 1;
  for (auto next_v: G[node]){
    // cpp_dump(next_v);
    if (seen[next_v]) continue;
    dfs(G, next_v, stamp);
  }
  last_order[node] = stamp++;
}

int main(){
  // input
  int N; cin >> N;
  graph ls(N+1);
  krep(i,1,N+1){
    int u,k;
    cin >> u >> k;
    rep(j,k){
      int v; cin >> v;
      ls[i].push_back(v);
    }
    sort(all(ls[i]));
  }

  // init
  seen.assign(N+1,0);
  seen[0] = 1;
  first_order.assign(N+1,0);
  last_order.assign(N+1,0);

  // dfs
  int node = 1;
  int stamp = 1;
  dfs(ls, node, stamp);


  krep(i, 1, N+1){
    cout << i << " ";
    cout << first_order[i] << " ";
    cout << last_order[i] << endl;
  }
}