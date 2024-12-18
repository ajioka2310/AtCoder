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
  llvec dist(N-1,0); rep(i,N-1) cin>>dist[i];
  llvec plan(M,0); rep(i,M) cin>>plan[i];
  llvec dist_sum(N,0);
  krep(i,1,N){
    dist_sum[i] = dist_sum[i-1]+dist[i-1];
  }
  // cpp_dump(dist,plan,dist_sum);

  int now = 0;
  ll ans = 0;
  rep(i,M){
    // cpp_dump(now,plan[i]);
    ans = ans+abs(dist_sum[now+plan[i]]-dist_sum[now]);
    ans = ans%100000;
    now = now+plan[i];
  }
  cout << ans << endl;
}
