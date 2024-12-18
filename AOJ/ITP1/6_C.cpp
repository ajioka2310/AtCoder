#include <bits/stdc++.h>
#include <cmath>
// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;
using namespace std;

#define ll long long
#define vec vector<int>
#define Graph vector<vector<int>>
// vectore

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* rep(i, n) {
        cout << i;
  }
*/
/* for (auto& x: X) {
        cin >> x;
    }
*/

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define all(v) v.begin(), v.end()

/*
%d : int
%.5f : 下5桁
%s : string
*/ 

void print_vec(vec v) {
    rep(i, (int)v.size()) {
        cout << v.at(i);
    }
    cout << endl;
}


int main() {
    int ls[4][3][10] = {{{0}}};
    int N;
    cin >> N;
    rep(i,N){
      int b,f,r,v;
      cin >> b >> f >> r >> v;
      ls[b-1][f-1][r-1] = max(ls[b-1][f-1][r-1]+v,0);
    }
    rep(i,4){
      rep(j,3){
        rep(k,10){
          cout << ' ' << ls[i][j][k];
        }
        cout << endl;
      }
      if(i<3){
        cout << string(20, '#') << endl;
      }

    }

}
