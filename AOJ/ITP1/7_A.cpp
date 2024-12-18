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

char judge(int m,int f,int r){
  if (m==-1 || f==-1){
    return 'F';
  }
  else if (m+f<30){
    return 'F';
  }
  else if (m+f<50 && r<50){
    return 'D';
  }
  else if (m+f<50 && r>=50){
    return 'C';
  }
  else if (m+f<65){
    return 'C';
  }
  else if (m+f<80){
    return 'B';
  }
  else{
    return 'A';
  }
}


int main() {
  while (true){
    int m,f,r;
    cin >> m >> f >> r;
    if (m+f+r==-3){
      break;
    }
    cout << judge(m,f,r) << endl;
  }
}
