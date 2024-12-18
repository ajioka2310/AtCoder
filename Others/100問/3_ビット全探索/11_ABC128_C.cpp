#include<bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

int main(){
  int N,M; cin >> N >> M;
  vec K(M,0);
  vector<set<int>> S(M);
  vec P(M,0);

  rep(i,M){
    cin >> K[i];
    rep(j,K[i]){
      int s; cin >> s;
      S[i].insert(s);
    }
  }
  rep(i,M){
    cin >> P[i];
  }
  int ans = 0;
  // switchの全状態
  rep_bit(bit,N){
    vec cond_switch(N,0);
    rep(i,N){
      if (bit & (1<<i)){
        cond_switch[i] = 1;
      }
    }
    // 電球の状態を調査
    vec cond_ligth(M,0);
    rep(i,M){
      rep(j,N){
        if (cond_switch[j]==1 && S[i].contains(j+1)){
          cond_ligth[i] += 1;
        }
      }
      cond_ligth[i] = cond_ligth[i]%2;
    }
    // ついているか判定
    if (P==cond_ligth){
      ans += 1;
    }
  }
  cout << ans;
  
}