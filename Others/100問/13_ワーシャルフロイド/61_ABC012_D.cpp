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


int main(){
  int N,M; cin>>N>>M;
  Graph graph(N,vec(N,INF));
  rep(i,M){
    int a,b,t;cin>>a>>b>>t;
    graph[a-1][b-1] = t;
    graph[b-1][a-1] = t;
  }
  // cpp_dump(graph);
  // 経由
  rep(k,N){
    // 出発
    rep(i,N){
      // 到着
      rep(j,N){
        graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
      }
    }
  }

  int ans = INF;
  rep(i,N){
    int _ans = -1;
    rep(j,N){
      if (i==j) continue;
      _ans = max(_ans,graph[i][j]);
    }
    ans = min(ans,_ans);
  }
  // cpp_dump(graph);
  cout << ans << endl;
}
