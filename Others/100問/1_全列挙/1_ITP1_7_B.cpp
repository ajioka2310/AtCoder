#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long
#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define all(v) v.begin(), v.end()

/*
%d : int
%.5f : 下5桁
*/ 

int main() {
  // N,M
  while (true){
    int N, M;
    cin >> N >> M ;
    if(N+M==0){
      break;
    }
    int ans = 0;
    krep(i,1,N+1){
      krep(j,i+1,N+1){
        krep(k,j+1,N+1){
          if (i+j+k==M){
            ans += 1;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
