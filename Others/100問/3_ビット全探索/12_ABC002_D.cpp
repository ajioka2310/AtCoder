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
  vec X(M,0),Y(M,0);
  rep(i,M){
    cin >> X[i] >> Y[i];
  }

  vector<set<int>> ls(N);
  rep(i,M){
    ls[X[i]-1].insert(Y[i]-1);
    ls[Y[i]-1].insert(X[i]-1);
  }

  int ans = 0;
  rep_bit(bit,N){
    int cnt = bitset<32>(bit).count();
    vec cond(N,0);
    rep(i,N){
      if(bit&(1<<i)){
        cond[i] = 1;
      }
    }
    bool flg = true;
    rep(i,N){
      rep(j,N){
        if (i!=j && cond[i]==1 && cond[j]==1 && !ls[i].contains(j)){
          flg = false;
        }
      }
    }

    if(flg){
      ans = max(ans,cnt);
    }
  }
  cout << ans << endl;
}