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
#define all(a) (a).begin(), (a).end()


#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
namespace cp = cpp_dump;

const int INF=INT_MAX/2;



int main(){
  // input
  int V,E;cin>>V>>E;
  Graph graph(V,vec(V,INF));
  rep(i,E){
    int s,t,d;cin>>s>>t>>d;
    graph[s][t] = d;
  }
  cpp_dump(graph | cp::dec(2) | cp::index());

  Graph dp(1<<V,vec(V,INF));
  dp[1][0] = 0;
  rep_bit(bit,V){
    rep(i,V){
      rep(j,V){
        if ((bit & (1<<i)) && !(bit & (1<<j))){

          int target = bit | (1<<j);
          dp[target][j] = min(
            dp[target][j],
            dp[bit][i] + graph[i][j]
          );
          // cpp_dump(dp);
        }
      }
    }
  }
  cpp_dump(dp | cp::dec(2) | cp::index());

}


  



