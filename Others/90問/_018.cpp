#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define ll long long
#define vec vector<int>
#define llvec vector<long long>
#define Graph vector<vector<int>>
#define llGraph vector<vector<ll>>
#define pair_int pair<int,int>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); ++i)
#define rep_bit(bit,n) for (int bit = 0; bit < (1<<n); ++bit)
#define rep_auto(i,A) for (auto& i:A)
#define all(a) (a).begin(), (a).end()
const int INF=INT32_MAX/2;
const int MOD=10007;

inline string YESNO(bool cond) {return cond ? "YES" : "NO";}
inline string yesno(bool cond) {return cond ? "yes" : "no";}
inline string YesNo(bool cond) {return cond ? "Yes" : "No";}


#include "/workspaces/AtCoder-cpp-env-main/cpp-dump/cpp-dump.hpp"
namespace cp = cpp_dump;

void calc(int T,int L,int X, int Y, int E){
  //(x,y,z)
  double x1 = 0;
  double y1 = -L*sin(2.0*M_1_PI*E/T)/2.0;
  double z1 = (L/2.0) - (L/2.0)*cos(2.0*M_1_PI*E/T);
  double x2 = X;
  double y2 = Y;
  double A = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  double B = z1;
  cout << atan2(B,A)*180.0L / M_1_PI << endl;  
}

int main(){
  int T; cin>>T;
  int L,X,Y; cin>>L>>X>>Y;
  int Q; cin>>Q;
  rep(i,Q){
    int E; cin>>E;
    calc(T,L,X,Y,E);
  }
}
