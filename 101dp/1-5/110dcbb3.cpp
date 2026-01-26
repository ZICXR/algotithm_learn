#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;

int n, m, f[N], g[N], q[N];
// i => 0 -> n-1
//   j => 0 -> v - 1  余数  为什么是余数？ 
// 如果余数是 r 那么最小的就是f[i, r] 然后是 f[i, r + v], f[i, r + 2v] ...
// 这样就可以从r开始迭代  每多考虑一种物品 就要更新f
// 相当于 f[j] = max(g[j], g[j-v] + w, g[j-2v] + 2w, ...)  也就是先考虑f[r]  r => [0, v-1]
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {  // 遍历物品
        int v, s, w;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f); // g ==> f 在 i-1 层的数据
        for (int j = 0; j < v; j ++){// 余数
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v) {  // 遍历 g  维护 g 的单调队列  向上 这里循环一遍 就得出了 一个窗口的额最大值
                // 一层里面用单调队列维护最大值
                if (hh <= tt && q[hh] < k - s * v) hh ++;  // 判断队头  窗口步长是v 窗口里面存s个数 窗口大小 s * v 
                // 要用上一层g  更新本层内f[k] 的值  怎么更新？ 那就是从(k - s, k) 这个窗口里面g的最大值 更新 f[k]这个值 
                // 截至到 (k - s, k) 窗口中 g 里面的 最大值 g[q[hh]]  上下层转换还应该加w 加几个w? ==> (x - q[hh]) / v 个 因为要从q[hh] 更新到 k 
                // 步长是 v, 当前值是q[hh],  所以应该是(k - q[hh]) / v 个w 
                if (hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w); // 放 (k - q[hh]) / v个物品
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt --;  // 维护单调队列  我要维护的是最大的
                // 维护的是加上若干w之后的大小顺序  但是 g[] 本身没有加 w 所以在   f[k] = max() 时会加w 
                // g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w
                // => g[q[tt]] + (k - q[tt]) / v * w <= g[k] + (k - k) / v * w
                // 这里的意思是 q[tt] 对应的项 在计算f[k] 时 加上若干w 之后 小于等于 k对应的项 在计算f[k] 时 加上若干w

                //最终价值 = g[x] + (k-x)/v * w
                //    = g[x] + (k-j)/v * w - (x-j)/v * w  【把(k-x)拆成(k-j)-(x-j)】 
                //    = [g[x] - (x-j)/v * w] + (k-j)/v * w  k 不变  取最大值 ==> 等价于 g[x] - (x-j)/v * w取最大值
                 q[++ tt] = k;
                // g[x] 是 上一层 体积不超过 x 的最大价值  
            }
        } 

            
    }
    cout << f[m] << endl;    
    return 0;
}



