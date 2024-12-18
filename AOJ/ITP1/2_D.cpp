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



int main() {
  vec ls(3);
  
  rep(i, 3){
    cin >> ls[i];
  }

  sort(ls.begin(),ls.end());

  cout << ls[0] << ' '<< ls[1]<<' '<<ls[2] <<endl;
}
