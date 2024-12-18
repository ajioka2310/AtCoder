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
    int N,M;
    cin >> N >> M;
    int A[100][100] = {{0}};
    int B[100] = {0};
    int C[100] = {0};
    rep(i,N){
      rep(j,M){
        cin >> A[i][j];
      }
    }
    rep(i,M){
      cin >> B[i];
    }
    int ans = 0;
    
    rep(i,N){
      rep(j,M){
        C[i] += A[i][j] * B[j];
      }
    }

    rep(i,N){
      cout << C[i] << endl;
    }


}
