#include <iostream>

using namespace std;

const int N = 1010;

int w[5] = {0, 10, 20, 50, 100};
int f[N];

// 优化掉一维
// f[i][j] = f[i - 1][j];  // 这时候 从上一层保留下来的值就是f[i - 1][j] 优化成一维 f[j] 相等
// if (j >= w[i]) f[i][j] += f[i][j -  w[i]];  // j - wi 是本层的值，所以使用到本层的小值 要从小到大遍历
// ==》
// f[j] = f[j];  // 无意义
// if (j >= w[i]) f[j] += f[j -  w[i]];
// ==》
// if (j >= w[i]) f[j] += f[j -  w[i]];
int main() {
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= 4; i ++) 
        for (int j = 0; j <= n; j ++) {
            if (j >= w[i]) f[j] += f[j -  w[i]]; 
        }
    cout << f[n] << endl;
    return 0;
}

// int f[5][N];
// 优化掉一个循环
// f(i, j) = max(f(i - 1, j), f(i, j - v) + w)
// f(i - 1, j)必定存在 但是f(i, j - v) + w)不一定存在  判断

// int main() {
//     int n;
//     cin >> n;
//     f[0][0] = 1;
//     for (int i = 1; i <= 4; i ++) 
//         for (int j = 0; j <= n; j ++) {
//             f[i][j] = f[i - 1][j];
//             if (j >= w[i]) f[i][j] += f[i][j -  w[i]]; 
//         }
//     cout << f[4][n] << endl;
//     return 0;
// }


// int f[5][N];
// 最朴素版本
// int main() {
//     int n;
//     cin >> n;
//     f[0][0] = 1;
//     for (int i = 1; i <= 4; i ++) 
//         for (int j = 0; j <= n; j ++) {
//            for (int k = 0; k * w[i] <= j; k ++)
//             f[i][j] += f[i - 1][j - k * w[i]];
//         }
//     cout << f[4][n] << endl;
// return 0;
// }







