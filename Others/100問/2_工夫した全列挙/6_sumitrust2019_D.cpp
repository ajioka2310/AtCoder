#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()


bool check(string S,int i,int j,int k){
  int length = S.length();
  bool flg = false;
  vec ls(3);
  vector<char> number = {'0','1','2','3','4','5','6','7','8','9'};
  rep(l,length){
    if (S[l]==number[i] && ls[0]==0){
      ls[0] = 1;
    }
    else if (S[l]==number[j] && ls[0]==1 && ls[1]==0){
      ls[1] = 1;
    }
    else if (S[l]==number[k] && ls[0]==1 && ls[1]==1 && ls[2]==0){
      ls[2] = 1;
    }
  }
  if (ls[2]==1){
    flg = true;
  }
  return flg;
}


int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    krep(i,0,10){
      krep(j,0,10){
        krep(k,0,10){
          if (check(S,i,j,k)){
            ans +=1;
          }
        }
      }
    }
    cout << ans;    
}