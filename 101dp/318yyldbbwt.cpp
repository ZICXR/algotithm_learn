#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int h[N], e[N], ne[N], idx;
int f[N][N], v[N], w[N];
int n, m;

void add(int u, int v) {
    // v 保存在 idx  v 指向 u 所在的头节点  u 指向 下表为 idx 节点 也就是 v
    e[idx] = v, ne[idx] = h[u], h[u] = idx ++;
}

void dfs(int u) {
    for (int i = h[u]; ~i; i = ne[i]) {  // 遍历 u 的子树  物品组
        int son = e[i];
        dfs(e[i]); // 下标为 i, 对应的编号
        // 必须要加 u 这个点  所以要减去 v[u]
        for (int j = m - v[u]; j >= 0; j --)  // 体积
            for (int k = 0; k <= j; k ++)  // 这里是决策  这里是按照体积选 而不是按照物品的组合
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
    }   
    // 物品加入
    for (int i = m; i >= v[u]; i --) f[u][i] = f[u][i - v[u]] + w[u];
    for (int i = 0; i < v[u]; i ++) f[u][i] = 0; // u 加不进去
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);  // 保存头节点
    int root;
    for (int i = 1; i <= n; i ++) {
        int p;
        scanf("%d%d%d", &v[i], &w[i], &p);
        if (p == -1) root = i;
        else add(p, i); // i 依赖 p 也就是 p 是 i 的父节点  因为当一个子节点被加入时，父节点必须加入 所以子节点依赖父节点
    }
    dfs(root);  // 从根节点开始递归
    cout << f[root][m] << endl;  // 从根节点的树 里面 体积不超过 m 的最大价值
    return 0;
}

/*
邻接表存图
h[k]  这里是指 编号为k的节点的头节点指针  不是下标是k 而是 e[t] = k 的那个节点

*/









