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
// namespace cp = cpp_dump;


int main(){
  // input
  int H,W,N; cin >> H >> W >> N;
  vector<vector<char>> map(H+2,vector<char>(W+2,'X'));
  vector<pair<int,int>> point(N+1);
  krep(i,1,H+1){
    krep(j,1,W+1){
      char c; cin >> c;
      if(c=='S'){
        map[i][j] = '.';
        point[0] = {j,i};
      }
      else if (c=='.'||c=='X'){
        map[i][j] = c;
      }
      else{
        map[i][j] = '.';
        point[int(c-'0')] = {j,i};
      }
    }
  }
  // cpp_dump(map);
  // cpp_dump(point);

  int ans = 0;
  rep(i,point.size()-1){
    pair<int,int> st,ed;
    st = point[i];
    ed = point[i+1];
    Graph dist(H+2,vec(W+2,-1));
    rep(i,H+2){
      rep(j,W+2){
        if (i==0||i==H+1||j==0||j==W+1) dist[i][j] == -9999;
      }
    }
    queue<pair<int,int>> que;
    // cpp_dump(st,ed,dist);

    // init 
    dist[st.second][st.first] = 0;
    que.push(st);
    while(!que.empty()){
      pair<int,int> now;
      now = que.front();
      // cpp_dump(que,now);
      que.pop();
      // cpp_dump(now.second,now.first);
      // cpp_dump(map);
      // cpp_dump(map[now.second+1][now.first]);
      // cpp_dump(dist[now.second+1][now.first]);
      if (map[now.second+1][now.first]=='.'&&dist[now.second+1][now.first]==-1){
        que.push({now.first,now.second+1});
        dist[now.second+1][now.first] = dist[now.second][now.first] + 1;
      }
      if (map[now.second-1][now.first]=='.'&&dist[now.second-1][now.first]==-1){
        que.push({now.first,now.second-1});
        dist[now.second-1][now.first] = dist[now.second][now.first] + 1;
      }
      if (map[now.second][now.first+1]=='.'&&dist[now.second][now.first+1]==-1){
        que.push({now.first+1,now.second});
        dist[now.second][now.first+1] = dist[now.second][now.first] + 1;
      }
      if (map[now.second][now.first-1]=='.'&&dist[now.second][now.first-1]==-1){
        que.push({now.first-1,now.second});
        dist[now.second][now.first-1] = dist[now.second][now.first] + 1;
      }

    }
  ans += dist[ed.second][ed.first];
  // cpp_dump(st,ed,dist);
  }
  cout << ans << endl;
}