#include <bits/stdc++.h>
#include <cmath>
#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
namespace cp = cpp_dump;
using namespace std;

#define ll long long
#define vec vector<int>
#define Graph vector<vector<int>>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define all(v) v.begin(), v.end()

/*
%d : int
%.5f : 下5桁
*/ 

int main() {
  string s = "Hello";
  int N = s.size();
  rep(i,N){
    cout << s.substr(i) << endl;
  }
  rep(i,N){
    rep(j,N-i+1){
      cout << s.substr(i,j) << endl;
    }
  }
  cpp_dump(some_huge_vector | cp::back(10) | cp::both_ends(5) | cp::dec(2));
  // ベクターのインデックスを表示します。
  cpp_dump(some_huge_vector | cp::dec(2) | cp::index());
}
