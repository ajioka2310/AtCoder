#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>

#define graph vector<vector<int>>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(a) (a).begin(), (a).end()

// #include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
// namespace cp = cpp_dump;

int main(){
  int N; cin >> N;
  vec P(N,0),Q(N,0);
  rep(i,N) cin >> P[i];
  rep(i,N) cin >> Q[i];
  vec ls1(N,0); krep(i,1,N+1) ls1[i-1]=i;
  vec ls2(N,0); krep(i,1,N+1) ls2[i-1]=i;

  int a=0; int b=0;

  do{
    if(P==ls1) break;
    a += 1;
  }
  while(next_permutation(all(ls1)));

  do{
    if(Q==ls2) break;
    b += 1;
  }
  while(next_permutation(all(ls2)));
  cout << abs(a-b) << endl;
}