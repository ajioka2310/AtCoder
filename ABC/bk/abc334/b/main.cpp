#include <iostream>
#include <algorithm>
using namespace std;

// ceil(a / b) を計算する関数
long long ceil_div(long long a, long long b) {
    if (b == 0) {
        throw invalid_argument("Division by zero");
    }
    // b > 0 の場合
    if (b > 0) {
        if (a >= 0) {
            return (a + b - 1) / b;
        } else {
            return a / b;
        }
    } 
    // b < 0 の場合
    else {
        if (a <= 0) {
            return (a + b + 1) / b;
        } else {
            return a / b;
        }
    }
}

// floor(a / b) を計算する関数
long long floor_div(long long a, long long b) {
    if (b == 0) {
        throw invalid_argument("Division by zero");
    }
    // b > 0 の場合
    if (b > 0) {
        if (a >= 0) {
            return a / b;
        } else {
            if (a % b == 0) {
                return a / b;
            } else {
                return (a / b) - 1;
            }
        }
    } 
    // b < 0 の場合
    else {
        if (a <= 0) {
            return a / b;
        } else {
            if (a % b == 0) {
                return a / b;
            } else {
                return (a / b) - 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long A, M, L, R;
    cin >> A >> M >> L >> R;
    
    // k が整数であることから、M は正の数
    // ただし、問題文では M >=1 なので、M >0
    // しかし、ceil_div と floor_div は汎用的に書いてあります
    
    // k >= ceil( (L - A) / M )
    // k <= floor( (R - A) / M )
    long long numerator_start = L - A;
    long long numerator_end = R - A;
    
    long long start_k = ceil_div(numerator_start, M);
    long long end_k = floor_div(numerator_end, M);
    
    // 結果の計算
    long long count = max(0LL, end_k - start_k + 1);
    
    cout << count << "\n";
    
    return 0;
}