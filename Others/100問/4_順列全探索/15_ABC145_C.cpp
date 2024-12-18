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


int main(){
  int N; cin >> N;
  vector<double> X(N,0),Y(N,0);
  rep(i,N) cin >> X[i] >> Y[i];
  vec ls(N,0);
  rep(i,N) ls[i] = i;
  double ans = 0;
  int cnt = 0;
  do {
    double distance = 0;
    krep(i,1,N){
      distance += sqrt(pow(X[ls[i]]-X[ls[i-1]],2)+pow(Y[ls[i]]-Y[ls[i-1]],2));
    }
    ans += distance;
    cnt += 1;
  }
  while(next_permutation(all(ls)));
  cout << fixed << setprecision(10) << ans/cnt << endl;

}