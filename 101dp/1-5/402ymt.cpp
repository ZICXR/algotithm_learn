#include <iostream>
#include <vector>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

vector<int> s;
vector<int> head[M];

int n, m;
int f[N][M];  // 前 i 行摆好，第 i 行是 a i-1 行是b 的方案
int g[N];  




int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < m; j ++) {
            int t;
            cin >> t;
            g[i] += !t << j;  // 坏的是0 后续‘与’之后不考虑这种情况  ==》 取反之后 移到对应位置 若‘与’结果不是0， 就是有坏的
        }
    // 先获取合法状态
    for (int i = 0; i < 1 << m; i ++) {  // 注意这里是 m 因为是一个状态是一行  所以状态的二进制要能把这一行的每一列的数表示出来
        // 相邻不能有
        if (!(i & i >> 1)) s.push_back(i);
    }
    // 状态转移
    for (int i = 0; i < s.size(); i ++)
        for (int j = 0; j < s.size(); j ++) {
            int a = s[i], b = s[j];
            if ((a & b) == 0) head[i].push_back(j);  // 上下交错
        }
    
    // 计算
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i ++)
        for (int a = 0; a < s.size(); a ++)
            for (int b : head[a]) {
                if(g[i] & s[a]) continue;  // 有坏的
                f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
            }
    cout << f[n + 1][0] << endl;
    return 0;
}










