#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()




int main(){
  int N;
  cin >> N;
  vector<vector<ll>> A(N,vector<ll>(2));
  vector<ll> B(N*2);
  rep(i,N){
    rep(j,2){
      cin >> A[i][j];
      B[2*i+j] = A[i][j];
    }
  }
  ll ans = INF;

  rep(i,N*2){
    rep(j,N*2){
      ll tmp_ans = 0;
      ll st = B[i];
      ll ed = B[j];
      rep(k,N){
        tmp_ans += abs(st-A[k][0]) + abs(A[k][0]-A[k][1]) + abs(A[k][1]-ed);
      }
      ans = min(ans,tmp_ans);
    }
  }
  cout << ans;    
}