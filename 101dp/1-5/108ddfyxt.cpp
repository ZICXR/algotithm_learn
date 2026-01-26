#include <iostream>
#include <algorithm>


using namespace std;


const int N = 55;

int up[N], down[N], w[N];
int n, ans;

void dfs(int u, int su, int sd) {
    if (su + sd >= ans) return;// 两种之和个数大于最坏情况，返回
    if (u == n) {
        ans = sd + su;
        return;
    }
    int k = 0;
    // 情况1 u 放到上升子序列
    while(k < su && up[k] >= w[u]) k ++;  // up 中找w[u] 第一个大于的数所在的序列
    int t = up[k];  // 后续回复现场
    up[k] = w[u];  // 将当前节点加到序列中
    if (k >= su) dfs(u + 1, su + 1, sd);  // 如果 新开了一个集合 上升子序列个数应该加1 
    else dfs(u + 1, su, sd);  // 否则不加1

    up[k] = t; // 回复现场
    k = 0;
    
    // 情况2 u 放入到下降自序里
    while (k < sd && down[k] <= w[u]) k ++;
    t = down[k];
    down[k] = w[u];
    if (k >= sd) dfs(u + 1, su, sd + 1);
    else dfs(u + 1, su, sd);

    down[k] = t;

}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; i ++) scanf("%d", &w[i]);
        ans = n; // 最坏情况
        dfs(0 , 0 ,0);
        cout << ans << endl;
    }
    return 0;
}




