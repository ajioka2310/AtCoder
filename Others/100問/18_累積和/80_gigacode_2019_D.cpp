#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define llGraph vector<vector<ll>>
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
  ll H,W,K,V; cin>>H>>W>>K>>V;
  llGraph graph(H,llvec(W));
  rep(i,H){
    rep(j,W){
      cin>>graph[i][j];
    }
  }
  // 累積和をとる
  llGraph graph_sum(H+1,llvec(W+1,0));
  krep(i,1,H+1){
    krep(j,1,W+1){
      graph_sum[i][j] = graph[i-1][j-1]+graph_sum[i-1][j]+graph_sum[i][j-1]-graph_sum[i-1][j-1];
    }
  }
  int ans = 0;
  krep(a,1,H+1){
    krep(b,1,W+1){
      krep(c,a,H+1){
        krep(d,b,W+1){
          // 土地代
          ll ans1 = graph_sum[c][d]-graph_sum[a-1][d]-graph_sum[c][b-1]+graph_sum[a-1][b-1];
          ll ans2 = (c-a+1)*(d-b+1)*K;
          if (ans1+ans2<=V) ans = max(ans,(c-a+1)*(d-b+1));
        }
      }
    }
  }
  cout << ans << endl;

}
