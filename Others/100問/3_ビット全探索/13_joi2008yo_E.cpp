#include<bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()
int main(){
  int R,C; cin >> R >> C;
  graph A(R,vec(C,0));
  rep(i,R){
    rep(j,C){
      cin >> A[i][j];
    }
  }

  int ans = 0;
  rep_bit(bit,R){
    vec ls(R,0);
    rep(i,R){
      if(bit & (1<<i)){
        ls[i]=1;
      }
    }
    graph B(R,vec(C,0));
    rep(i,R){
      if (ls[i] == 1){
        rep(j,C){
          if (A[i][j]==1){
            B[i][j] = 0;
          }
          else{
            B[i][j] = 1;
          }
        }
      }
      else{
        rep(j,C){
          B[i][j] = A[i][j];
        }
      }
    }
    int _ans = 0;
    rep(i,C){
      int cnt = 0;
      rep(j,R){
        if (B[j][i]==0){
          cnt += 1;
        }
      }
      _ans += max(cnt,R-cnt);

    }
    ans = max(ans,_ans);
  }
  cout << ans << endl;

}