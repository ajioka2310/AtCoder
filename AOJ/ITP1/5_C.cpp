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
    while(true){
        int H,W;
        cin >> H >> W;
        if(H+W==0){
            break;
        }
        else{
            rep(i,H){
                rep(j,W){
                    if((i+j)%2==0){
                        cout<<"#";
                    }
                    else {
                        cout<<".";
                    }
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
}
