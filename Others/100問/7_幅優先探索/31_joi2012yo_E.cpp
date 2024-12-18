#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>

#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"


int main(){
  // input
  int W,H; cin>>W>>H;
  Graph graph(H+2,vec(W+2,0));
  krep(i,1,H+1){
    krep(j,1,W+1){
      int tmp; cin>> graph[i][j];
    }
  }

  // init
  Graph seen = graph;
  Graph dist(H+2,vec(W+2,-1));
  seen[0][0] = 1;
  dist[0][0] = 0;
  queue<pair<int,int>> que;
  que.push({0,0});
  while (!que.empty())
  {
    pair<int,int> now = que.front();que.pop();
    int x = now.first;
    int y = now.second;

    for (auto idy : {-1,0,1}){
      for (auto idx: {-1,0,1}){
        if (idy==0 && idx==0) continue;
        if (idy==-1 && idx==1 && now.second%2==0) continue;
        if (idy==1 && idx==1 && now.second%2==0) continue;
        if (idy==-1 && idx==-1 && now.second%2==1) continue;
        if (idy==1 && idx==-1 && now.second%2==1) continue;
        if (x+idx<0 || x+idx>W+1) continue;
        if (y+idy<0 || y+idy>H+1) continue;
        int next_x = x+idx;
        int next_y = y+idy;
        if (seen[next_y][next_x] == 0 & graph[next_y][next_x]==0){
          seen[next_y][next_x] = 1;
          que.push({next_x,next_y});
        }
      }
    }
    
  }
  
  // cpp_dump(seen);

  krep(i,1,H+1){
    krep(j,1,W+1){
      if (seen[i][j]==0){
        graph[i][j] = 1;
      }
    }
  }

  int ans = 0; 

  krep(i,1,H+1){
    krep(j,1,W+1){
      if (graph[i][j]==1){
        int count = 0;
        for (auto idy : {-1,0,1}){
          for (auto idx: {-1,0,1}){
            if (idy==0 && idx==0) continue;
            if (idy==-1 && idx==1 && i%2==0) continue;
            if (idy==1 && idx==1 && i%2==0) continue;
            if (idy==-1 && idx==-1 && i%2==1) continue;
            if (idy==1 && idx==-1 && i%2==1) continue;
            int next_x = j+idx;
            int next_y = i+idy;
            if (graph[next_y][next_x] == 0){
              count += 1;
            }
          }
        }
        ans += count;
      }
    }
  }


  // cpp_dump(graph);
  cout << ans << endl;
}