#include <iostream>
#include <algorithm>


using namespace std;

const int N = 1010;

int tt, mm;

// int t[N], m[N];
// int f[N][N];

// int main() {
//     cin  >> tt >> mm;
//     for (int i = 1; i <= mm; i ++) scanf("%d%d", &t[i], &m[i]);
//     for (int i = 1; i <= mm; i ++) 
//         for (int j = 0; j <= tt; j ++) {
//             f[i][j] = f[i - 1][j];
//             if (t[i] <= j) f[i][j] = max(f[i - 1][j - t[i]] + m[i], f[i][j]);
//         }
//     cout << f[mm][tt] << endl;
//     return 0;
// }

// 优化
// 一维数组优化 -> f[j] 表示 第i层时间不超过j的最大的选择价值 
// f[i][j] = max(f[i - 1][j - t[i]] + m[i], f[i][j]); 
// 这里是从上一层转化来的， 而且算j 时 用到但是这里计算j时 需要用到上一层的比j小的j-t[i]，所以这里要逆序遍历时间 如果正序遍历 则会提前覆盖掉j-t[i]的值
int f[N];
int main() {
    cin  >> tt >> mm;
    for (int i = 1; i <= mm; i ++) {
        int t, m;
        cin >> t >> m;
        for (int j = tt; j >= t; j --) f[j] = max(f[j], f[j - t] + m);
    }
    cout << f[tt] << endl;   
    return 0;
}



