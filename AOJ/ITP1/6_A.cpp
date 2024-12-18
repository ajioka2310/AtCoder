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

void print_vec(vec v) {
    rep(i, (int)v.size()) {
        cout << v.at(i) << ' ';
    }
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    vec A(n);
    rep(i,n){
        cin >> A[i];
    }
    reverse(all(A));
    rep(i,n-1){
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);



}
