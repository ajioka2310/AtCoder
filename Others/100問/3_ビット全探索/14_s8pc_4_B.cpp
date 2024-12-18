#include<bits/stdc++.h>
using namespace std;


#define vec vector<int>
#define llvec vector<long long>

#define graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()



int main(){
  int N,K; cin >> N >> K;
  llvec A(N,0); rep(i,N) cin >> A[i];
  long long ans = 1e18;

  rep_bit(bit,N){
    vec cond(N,0);
    rep(i,N){
      if(bit&(1<<i)) cond[i]=1;
    }
    // check
    llvec B=A;
    long long now=B[0];
    int colors=1;
    long long cnt=0;
    krep(i,1,N){
      // 
      if(cond[i]==1){
        // ビルを伸ばす。
        if(B[i]-now>0){
          now = B[i];
          colors += 1;
        }
        else{
          now = now + 1;
          colors += 1;
          cnt += now - B[i];
        }
      }
      else{
        if(B[i]-now>0){
          now = B[i];
          colors += 1;
        }
      }
    }
    if (K<=colors){
      ans = min(ans,cnt);
    }

  }
  cout << ans << endl;

}