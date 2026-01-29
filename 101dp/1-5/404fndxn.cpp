#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;

const int N = 18, M = 1 << 18;
const double eps = 1e-8;

int n, m;
PDD q[N];
int path[N][N];  // 二进制状态  十进制 =》二进制 01010 表示这条抛物线覆盖 第二、四个点 下标 1 3
int f[M];

int cmp(double x1, double x2) {
    if (fabs(x1 - x2) < eps) return 0;
    if (x1 > x2) return 1;
    return -1;
}


int main() {
    int T;
    cin >> T;
    while (T --) {
        cin >> n >> m;
        for (int i = 0; i < n; i ++) cin >> q[i].x >> q[i].y;

        // path[i, j] 表示 穿过 i,j 这个点的抛物线 可以覆盖哪些点
        memset(path, 0, sizeof path);
        for (int i = 0; i < n; i ++) {
            path[i][i] = 1 << i;  // 抛物线只覆盖自己  避免不能和其他点组成抛物线
            for (int j = 0; j < n; j ++) {
                double x1 = q[i].x, y1 = q[i].y;
                double x2 = q[j].x, y2 = q[j].y;
                if (!cmp(x1, x2)) continue;
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                if (cmp(a, 0) >= 0) continue;
                double b = (y1 / x1) - a * x1;
                int state = 0;  // 赋值
                for (int k = 0; k < n; k ++) {  // 枚举哪些点会被这条抛物线覆盖
                    double x = q[k].x, y = q[k].y;
                    // 找到哪个点在这个线上  并记录到状态
                    if (!cmp(y, a * x * x + b * x)) state += 1 << k;
                }
                path[i][j] = state;
            }
        }
        memset(f, 0x3f, sizeof f);
        f[0] = 0; // 0 这个状态表示不包含任何列 所以是0  二进制表示状态 0101 表示包含 二四列时的状态
        // 下面从 0 开始  因为这是更新 f[i | path[x][j]]
        for (int i = 0; i + 1 < 1 << n; i ++) { // 为什么是 i + 1 因为 当 i 是全1 时就没必要更新了 没有未选的值了
            int x = 0;
            // 找任意一个没有被覆盖到的点
            for (int j = 0; j < n; j ++)
                if (!(i >> j & 1)) {
                    x = j;
                    break;
                }
            
            for (int j = 0; j < n; j ++)  // 枚举所有过x的线 过 x 的抛物线覆盖的列 path[x][j]
            //  path[x][j] | i 对应的状态 的线少 还是 直接加一条线少
                f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
        }
        cout << f[(1 << n) - 1] << endl;


    }
    return 0;
}





