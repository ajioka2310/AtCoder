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

vec primes(int N){
  vec primes(N+1,1);
  primes[0] = primes[1] = 0;
  krep(i,2,int(pow(N,0.5))+1){
    if (primes[i]){
      for (int j = pow(i,2); j<N+1; j+=i) primes[j] = 0;
    }
  }
  return primes;
}


int main(){
  int Q; cin>>Q;
  Graph ls(Q,vec(2,0));
  rep(i,Q) cin>>ls[i][0]>>ls[i][1];

  vec ls_primes = primes(100000);
  vec ls_hit(100001,0);
  rep(i,100001){
    if(i%2==1){
      if(ls_primes[i]&ls_primes[(i+1)/2]) ls_hit[i]=1;
    }
  }
  // cpp_dump(ls_primes);

  // cpp_dump(ls_hit);

  krep(i,1,100001){
    ls_hit[i] = ls_hit[i-1]+ls_hit[i];
  }
  // cpp_dump(ls_hit);



  rep(i,Q){

    cout << ls_hit[ls[i][1]] - ls_hit[ls[i][0]-1] << endl;
  }


  
}
