#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long
#define vec vector<int>
#define Graph vector<vector<int>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define all(v) v.begin(), v.end()

/*
%d : int
%.5f : 下5桁
*/ 

int main() {
  // N,M
    int N;
    cin >> N;
    int ans = 0;
    krep(i,1,N+1){
        int cnt=0;
        krep(j,1,i+1){
            if(i%j==0){
                cnt += 1;
            }
        }
        if(cnt==8 && i%2==1){
            ans += 1;
        }
    }
    cout << ans << endl;
}
