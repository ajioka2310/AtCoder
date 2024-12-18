#include<bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

int main(){
  int n,q;
  cin >> n;
  vec A(n,0);

  rep(i,n){
    cin >> A[i];
  }
  cin >> q;
  vec M(q,0);
  rep(i,q){
    cin >> M[i];
  }

  set<int> calc;
  rep_bit(bit,n){
    vec ls(n,0);
    int ans = 0;
    rep(j,n){
      if (bit & (1<<j)){
        ans += A[j];
      }
    }
    calc.insert(ans);
  }



  rep(i,q){
    int m = M[i];
    
    if (calc.count(m)){
      cout << "yes" << endl;
    }
    else {
      cout << "no" << endl;
    }
  }
}