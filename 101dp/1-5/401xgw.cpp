#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

const int N = 12, M = 1 << 10, K = 110;  // N 棋盘边长  M 棋盘某一行状态  K 国王数量



vector<int> s; // 保存 0 ~ M 的所有合法状态
vector<int> head[M];  // 保存转移状态
int cnt[M];
int n, m;
LL f[N][K][M]; // 前 i 行 放了 j 个国王 且 第 i 行状态是 m 的集合

bool check(int k) {
    if (k & k >> 1) return false;
    return true;
}

int count_1(int t) {  // 统计1的数量
    int res = 0;
    for (int i = 0; i < n; i ++) res += t >> i & 1;  // & 1 只保留最低位
    return res;
}



int main() {
    cin >> n >> m;
    for (int i = 0; i < 1 << n ; i ++) 
        if (check(i)) {
            s.push_back(i);  // 是否是合法状态
            cnt[i] = count_1(i);
            // cout << cnt[i];
        }
    
    for (int i = 0; i < s.size(); i ++)  // 处理状态之间的而转移关系
        for (int j = 0; j < s.size(); j ++) {
            // a & b == 0    a | b 不能有连续的1 
            int a = s[i], b = s[j];
            // printf("%d %d     ", a & b,  (a | b) & ((a | b) >> 1));
            if ((a & b) == 0 && check(a|b)) {  // a 可以转移到 b
                head[i].push_back(j);  // 这里保存可已转移到的下标
            }
        }
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i ++)  // 这里 n + 1 后面好算结果
        for (int j = 0; j <= m; j ++) 
            for (int a = 0; a < s.size(); a ++)
                for (int b : head[a]) {
                    int c = cnt[s[a]];
                    if (j >= c)
                        f[i][j][a] += f[i - 1][j - c][b];
                }
    cout << f[n + 1][m][0] << endl;
    return 0;
}
