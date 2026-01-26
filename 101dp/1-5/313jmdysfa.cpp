#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define v first 
#define w second

typedef pair<int, int> PII;

const int N = 32010, M = 70;

int n, m, f[N];
PII master[M];
vector<PII> servent[M];



int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q)  // 主件
            master[i] = {v, v * p};
        else servent[q].push_back({v, v * p});
    }
    for (int i = 1; i <= m; i ++) {
        if (!master[i].v) continue;
        for (int j = n; j >= 0; j --) {
            for (int k = 0; k < 1 << servent[i].size(); k ++) {  // 二进制遍历 00 01 10 11
                int v = master[i].v, w = master[i].w;
                for (int u = 0; u < servent[i].size(); u ++)  // k = 1 01表示一个附件  k = 3 011 表示两个附件
                    if (k >> u & 1) {
                        v += servent[i][u].v;
                        w += servent[i][u].w;
                    }
                if (j >= v) f[j] = max(f[j], f[j - v] + w);
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}

