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
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
const int INF=INT32_MAX/2;
const int MOD=10007;

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;


int main(){
  int N;cin>>N;
  vec ls;  
  int now = N;

  while(true){
    bool flg = true;
    // cpp_dump(now);
    krep(i,2,max(int(pow(now,0.5))+1,3)){
      // cpp_dump(now,flg,i);
      if (now%i==0){
        now = now/i;
        ls.push_back(i);
        flg = false;
        // cpp_dump(now,flg,i);
        break;
      }
    }
    // cpp_dump(now,flg);

    if (flg==true){
      ls.push_back(now);break;
    }
  }

  // cpp_dump(ls);
  all(ls);
  cout << N << ": ";
  rep_auto(a,ls){
    cout << a << " ";
  }
  
}
