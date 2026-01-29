#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110, M = 1 << 10;
int g[N];
int n, m;
int f[2][M][M];  // 滚动数组

vector<int> state; // 所有可能的合法状态
int cnt[M]; // 合法状态对应的炮的个数

bool check(int state) {
    return !((state & state >> 1) || (state & state >> 2));
}

int count(int state) {
    int c = 0;
    for (int i = 0; i < m; i ++) {
        c += state >> i & 1;
    }
    return c;
}

int main() {
    cin >> n >> m;
    // 输入 并处理山地
    for (int i = 1; i <= n; i ++) 
        for (int j = 0; j < m; j ++) {
            char c;
            cin >> c;
            g[i] += (c == 'H') << j;
        }
    
    // 找到一行内所有可能出现的状态
    for (int i = 0; i < 1 << m; i ++)
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }
    
    // 找出所有的合法转移状态
    for (int i = 1; i <= n + 2; i ++) //  i 
        for (int j = 0; j < state.size(); j ++)  // j
            for (int k = 0; k < state.size(); k ++)  // k  前 i 行摆好了 第 i 行为 s[u]  i - 1 为 s[j] 
                for (int u = 0; u < state.size(); u ++) {  // 这里是第 i - 2 行状态
                    int a = state[j], b = state[k], c = state[u];
                    // 判断是否合法
                    if ((a & b) | (a & c) | (b & c)) continue;  // 不能上下连续是1
                    if (g[i] & b | g[i - 1] & a) continue;  // 是否有山地
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
                }
    
    cout << f[n + 2 & 1][0][0] << endl;

    return 0;
}





