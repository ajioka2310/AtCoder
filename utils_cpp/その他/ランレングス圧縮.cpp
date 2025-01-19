#include<bits/stdc++.h>
using namespace std;

int main(){
  string S; cin>>S;
  // ランレングス 圧縮でSを圧縮
  vector<pair<char,int>> rl;
  int cnt=1;
  rep(i,S.size()-1){
    if(S[i]==S[i+1]){
      cnt++;
    }else{
      rl.push_back({S[i],cnt});
      cnt=1;
    }
  }
  rl.push_back({S[N-1],cnt});
  dump(rl);
}
