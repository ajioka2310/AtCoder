#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define pair_int pair<int,int>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"


int main(){
  // input
  int H,W;cin>>H>>W;
  Graph map(H+2,vec(W+2,0));
  krep(i,1,H+1){
    krep(j,1,W+1){
      char s;cin>>s;
      if (s=='.') map[i][j] = 1;
      else map[i][j] = 0;
    }
  }

  // init
  Graph dist(H+2,vec(W+2,-1));
  dist[1][1] = 1;
  queue<pair_int> que;que.push({1,1});
  
  while (!que.empty()){
    // cpp_dump(que);
    pair_int now = que.front(); que.pop();
    // cpp_dump(now);

    int x = now.first;
    int y = now.second;
    for (auto idy: {-1,0,1}){
      for (auto idx: {-1,0,1}){
        if ((idx==0&&idy!=0)||(idy==0&&idx!=0)){
          if (map[y+idy][x+idx]==1&&dist[y+idy][x+idx]==-1){
            // cpp_dump(idx,idy);

            que.push({x+idx,y+idy});
            dist[y+idy][x+idx] = dist[y][x] + 1;
          }
        }
      }
    }
  }
  // cpp_dump(map);
  // cpp_dump(dist);
  // cpp_dump(dist[H][W]);

  int ans = 0;
  if (dist[H][W] == -1) ans = -1;
  else{
    ans += H*W;
    ans -= dist[H][W];
    krep(i,1,H+1){
      krep(j,1,W+1){
        if (map[i][j]==0) ans--;
      }
    }
  }
  cout << ans << endl;
}


  


