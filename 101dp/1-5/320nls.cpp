#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;


const int M = 10010, N = 110; // 最多 N * S 时间

struct Stone {
    int s, e, l;
    bool operator< (const Stone &W) const {
        return s * W.l < l * W.s;
    }
} stone[N];
int f[M];  // 恰好花费 j 的时间

int main() {
    int T;
    scanf("%d", &T);
    for (int C = 1; C <= T; C ++) {
        memset(f, -0x3f, sizeof f);
        f[0] = 0;
        int n, m = 0;  // m 表示如果吃了全部的总时间  m 赋初值！
        scanf("%d", &n);
        for (int i = 0; i < n; i ++) {
            scanf("%d%d%d", &stone[i].s, &stone[i].e, &stone[i].l);
            m += stone[i].s;
        }
        sort(stone, stone + n);
        for (int i = 0; i < n; i ++)
            for (int j = m; j >= stone[i].s; j --)
                f[j] = max(f[j], f[j - stone[i].s] + stone[i].e - stone[i].l * (j - stone[i].s)); // 前面消耗了j - stone[i].s时间
        
        int res = 0;
        for (int i = 0; i <= m; i ++) res = max(res, f[i]);        
        printf("Case #%d: %d\n", C, res);
    }
    return 0;
}



