#include <cstring>
#include <iostream>

using namespace std;

const int N = 55, mod = 1e9  +7;

int n, ne[N], f[N][N];
char t[N];

int main() {
    cin >> n >> t + 1;
    int m = strlen(t + 1);

    // 求 next 数组
    for (int i = 2, j = 0; i <= m; i ++) {
        while (j && t[i] != t[j + 1]) j = ne[j];
        if (t[i] == t[j + 1])  j ++;
        ne[i] = j;
    }

    // 求密码
    f[0][0] = 1; // 合法状态 前0步中 状态 0 (匹配不上) 的方案数是1
    for (int i = 0; i < n; i ++)  // n 步
        for (int j = 0; j < m; j ++)  // 每步 m + 1个状态 但是这里不能到m 所以是m个状态
            for (char k = 'a'; k <= 'z'; k ++) {  // 每个状态共有 26 个边
                int u = j;
                while (u && k != t[u + 1]) u = ne[u];
                if (k == t[u + 1]) u ++;  // 其实就是找到 密码的第 i 位 取值为 k 时 模板指针 j 是否最终指向最后一维
                if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
            }
    int res = 0;
    for (int i = 0; i < m; i ++) res = (res + f[n][i]) % mod;
    printf("%d\n", res);
    return 0;
}



