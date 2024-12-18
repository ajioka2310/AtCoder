#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector<int>
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define all(a) (a).begin(), (a).end()

int input() {
  // N
  int a;
  cin >> a;
  // s
  string s;
  cin >> s;
  // N,M
  int N, M;
  cin >> N >> M ;
  // A1, A2, ,,, AN
  vec A(N);
  rep(i,N){
    cin >> A.at(i);
  }

  /*
  A11, A12, ..., A1M
  A21,
  ..
  AN1, AN2, ..., ANM
  */ 
  vector<vector<ll>> a(N,vector<ll>(M));
  rep(i,N){
    rep(j,M){
      cin >> a[i][j];
    }
  }
  
string s1,s2;cin>>s1>>s2;
vector<char> ls1(s1.begin(),s1.end());
vector<char> ls2(s2.begin(),s2.end());
}

int output() {
  // N
  int N;
  cout << N << endl;

  /*
    A1, A2, ... , AN
  */
  vec A(N);
  rep(a,all(A)){
    cout << *a << endl;
  }
  /*
    A1, 
    A2,
    ...,
    AN
  */
  vec A(N);
  rep(a,all(A)){
    cout << *a << " ";
  }
  cout << endl;

  float f = 3.145900F;
  std::cout << std::setprecision(d) << std::scientific << f << std::endl;
  
  cout << fixed << setprecision(16);
  cout << res << endl;

}