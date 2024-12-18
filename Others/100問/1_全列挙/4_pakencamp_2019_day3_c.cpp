#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main(){
  // N,M
  int N, M;
  cin >> N >> M ;
  // A1, A2, ,,, AN
  vector<vector<ll>> A(N,vector<ll>(M));
  rep(i,N){
    rep(j,M){
      cin >> A[i][j];
    }
  }
  ll ans = 0;

  rep(i,M){
    krep(j,i+1,M){
      ll tmp_ans = 0;
      rep(k,N){
        tmp_ans += max(A[k][i],A[k][j]);
      }
      ans = max(ans,tmp_ans);
    }
  }

  cout << ans;
}