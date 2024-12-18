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
const int INF=INT32_MAX/2;


// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;




int main(){
  // input
  int N,M; cin>>N>>M;
  vector<vector<ll>> graph_dist(N+1,vector<ll>(N+1,INF));
  vector<vector<ll>> graph_time(N+1,vector<ll>(N+1,INF));

  rep(i,M){
    ll s,t,d,time; cin>>s>>t>>d>>time;
    graph_dist[s][t] = min(graph_dist[s][t],d);
    graph_dist[t][s] = min(graph_dist[t][s],d);
    graph_time[s][t] = min(graph_time[s][t],time);
    graph_time[t][s] = min(graph_time[t][s],time);
  }
  vector<vector<ll>> dp(1<<(N+1),vector<ll>(N+1,INF));
  // cpp_dump(graph_time);
  // cpp_dump(graph_dist);

  // init
  dp[2][1] = 0;
  // 一筆
  rep_bit(bit,N+1){
    krep(i,1,N+1){
      krep(j,1,N+1){
        if((bit&(1<<i))&&!(bit&(1<<j))){
          int bit_next = bit | (1<<j);
          if (dp[bit][i]+graph_dist[i][j]<=graph_time[i][j]){
            dp[bit_next][j] = min(
              dp[bit_next][j],
              dp[bit][i] + graph_dist[i][j]
            );
          }
        }
      }
    }
  }
  // cpp_dump(dp | cp::dec(2) | cp::index());
  // 戻る
  ll min_time=INF;
  krep(i,1,N+1){
    if (dp[(1<<(N+1)) - 2][i]+graph_dist[i][1] <= graph_time[i][1]){
      min_time = min(min_time,dp[(1<<(N+1)) - 2][i]+graph_dist[i][1]);
    }
  }

  ll count = 0;
  krep(i,1,N+1){
    if (dp[(1<<(N+1)) - 2][i]+graph_dist[i][1] <= graph_time[i][1]){
      if (min_time==dp[(1<<(N+1)) - 2][i]+graph_dist[i][1]){
        count += 1;
      }
    }
  }

  if (min_time==INF){
    cout << "IMPOSSIBLE" << endl;
  }
  else{
    cout << min_time << " " << count << endl;
  }
  // cpp_dump(dp);

}


  



