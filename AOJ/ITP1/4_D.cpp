#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long
#define vec vector<int>
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
*/ 

int main() {
    int n;
    cin >> n;
    ll sum=0;
    vec ls(n);

    rep(i,n){
        cin >> ls[i];
        sum += ls[i];
    }
    sort(all(ls));
    printf("%d %d %lld\n",ls[0], ls[n-1],  sum);
}
