#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;

const int N = 6010;

int n, m;

const int M = 2010; // logs 向上取整 乘 个数
int v[M], w[M], s[M], f[N];  // f[N] 要和 体积的范围保持一致

// 二进制优化
int main() {
    // 先打包
    cin >> n >> m;  // 奖品 金额
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        int vv, ww, ss;
        cin >> vv >> ww >> ss;  // 体积 价值 数量
        int k = 1;
        while (k <= ss) {  // jisuan 
            w[cnt] += k * ww;  // 价值
            v[cnt] += k * vv;  // 体积
            ss -= k;  // 减去已经分配好的
            k *= 2;
            cnt ++;
        }
        if (ss > 0) { // 还有一组
            w[cnt] += ss * ww;
            v[cnt] += ss * vv;
            cnt ++;
        }
    }
    // 01 背包
    for (int i = 1; i <= cnt; i ++) 
        for (int j = m; j >= v[i - 1]; j --)
            f[j] = max(f[j], f[j - v[i - 1]] + w[i - 1]);

    cout << f[m] << endl;
    return 0;

}




// 单调队列优化版
// int f[N], g[N], q[N];

// int main () {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++) {
//         int v, w, s;
//         cin >> v >> w >> s;
//         memcpy(g, f, sizeof f);
//         for (int r = 0; r < v; r ++) {
//             // 单调队列维护的是 g[k] 所以 k每次开始循环时 都要重新维护
//             int hh = 0, tt = -1;
//             for (int k = r; k <= m; k += v) {
//                 // 判断队头是不是移出去了
//                 if (hh <= tt && (k - q[hh]) / v  > s) hh ++; // q[hh] 才是下标
//                 // 更新最大值
//                 if (hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);  // 队头才是最大值
//                 // 维护单调队列
//                 while (hh <= tt && g[q[tt]] + (k - q[tt]) / v * w <= g[k]) tt --;
//                 q[++ tt] = k;
//             }
//         }
            
//     }
//     printf("%d", f[m]);
//     return 0;
// }




// 朴素版
// int f[N];



// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i ++) {
//         int v, w, s;
//         cin >> v >> w >> s;
//         for (int j = m; j >= v; j --)
//             for (int k = 0; k <= s && k * v <= j; k ++)
//                 f[j] = max(f[j], f[j - v * k] + k * w); // 加  kw 不是 w
//     }
//     cout << f[m];
        
//     return 0;
// }














