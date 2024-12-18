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
  int M,N; cin>>M>>N;
  int K; cin>>K;
  vector<Graph> graph(M,Graph(N,vec(3,0)));

  rep(i,M){
    string s; cin>>s;
    vector<char> ls(all(s));
    rep(j,N){
      if (ls[j]=='J') graph[i][j][0] = 1;
      if (ls[j]=='O') graph[i][j][1] = 1;
      if (ls[j]=='I') graph[i][j][2] = 1;
    }
  }

  vector<Graph> graph_sum(M+1,Graph(N+1,vec(3,0)));

  krep(i,1,M+1){
    krep(j,1,N+1){
      rep(k,3){
        graph_sum[i][j][k] = 
          graph[i-1][j-1][k]
          +graph_sum[i-1][j][k]
          +graph_sum[i][j-1][k]
          -graph_sum[i-1][j-1][k];
      }
    }
  }

  rep(i,K){
    int a,b,c,d; cin>>a>>b>>c>>d;
    vec ls(3);
    rep(j,3){
      int ans = 
        graph_sum[c][d][j] 
        - graph_sum[a-1][d][j]
        - graph_sum[c][b-1][j]
        + graph_sum[a-1][b-1][j];
      ls[j] = ans;
    }
    cout << ls[0] << ' ' << ls[1] << ' ' << ls[2] << endl;
  }

}
