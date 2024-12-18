#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main(){
  int m;
  cin >> m;
  vector<vector<int>> A1(m,vector<int>(2));
  rep(i,m){
    cin >> A1[i][0] >> A1[i][1];
  }
  int n;
  cin >> n;
  vector<vector<int>> A2(n,vector<int>(2));
  // map<int,map<int,int>> dict;
  set<pair<int,int>> ls;
  rep(i,n){
    cin >> A2[i][0] >> A2[i][1];
    ls.insert({A2[i][0],A2[i][1]});
  }
  
  int x,y;
  int tmp_x1 = A1[0][0];
  int tmp_y1 = A1[0][1];
  rep(j,n){
    int tmp_x2 = A2[j][0];
    int tmp_y2 = A2[j][1];
    int diff_x = tmp_x2-tmp_x1;
    int diff_y = tmp_y2-tmp_y1;
    bool flg = true;
    // 1~m の星の存在判定
    rep(k,m){
      if(!ls.count({A1[k][0]+diff_x,A1[k][1]+diff_y})){
          flg = false;
          break;
      }
    }

    if (flg){
      x = diff_x;
      y = diff_y;
      break;
    }
  }
  cout << x << ' ' << y << endl;    
}