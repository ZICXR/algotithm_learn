#include <cstring>
#include <iostream>
#include <algorithm>


using namespace std;

const int M = 25, N = 82;
const int INF = 0x3f;

int f[M][N];

int m ,n, cnt; // 氧气 氮气 气缸数

int main() {
    cin >> m >> n >> cnt;
    memset(f, INF, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= cnt; i ++) {
        int a, b, c;
        cin >> a >> b >> c;  // 氧气 氮气 重量
        for (int j = m; j >= 0; j --) {
            for (int k = n; k >= 0; k --) {
                int jj = j - a;
                int kk = k - b;
                if (jj < 0) jj = 0;  // 负数 也合法 但是不能用作索引 其实 提及至少是 负数 和 体积至少是0等价 
                // 所以这赋值之后 是体积至少大于零的状态
                if (kk < 0) kk = 0;
                f[j][k] = min(f[j][k], f[jj][kk] + c);
            }
        }
            
    }
    cout << f[m][n] << endl;
    return 0;
}






