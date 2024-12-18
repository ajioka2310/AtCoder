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

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}


// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;


int main(){
  int N; cin>>N;
  Graph A(N,vec(N,0)); rep(i,N){rep(j,N) cin>>A[i][j];}
  int M; cin>>M;
  Graph B(N,vec(N,1));
  rep(i,M){
    int X,Y; cin>>X>>Y;
    B[X-1][Y-1] = 0;
    B[Y-1][X-1] = 0;
  }
  vec ls(N,0);
  rep(i,N) ls[i] = i;
  int ans = INF;
  do{
    bool flg = true;
    rep(i,N-1){
      if(B[ls[i]][ls[i+1]]==0) flg = false;

    }
    if (flg==false) continue;
    int cand = 0;
    rep(i,N){
      cand += A[ls[i]][i];
    }
    ans = min(ans,cand);
  }
  while(next_permutation(all(ls)));
  if (ans==INF) cout << -1 << endl;
  else cout << ans << endl;
}
