#include <iostream>
#include <algorithm>




using namespace std;

const int N = 110;

int nn, vv, s[N];
int v[N][N], w[N][N], f[N];


int main() {
    cin >> nn >> vv;
    for (int i = 1; i <= nn; i ++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j ++) {
            scanf("%d%d", &v[i][j], &w[i][j]);
        }
    }

    for (int i = 1; i <= nn; i ++) 
        for (int j = vv; j >= 0; j --)
            for (int k = 0; k <= s[i]; k ++)
                if (j >= v[i][k]) // 要判断能否放下
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[vv] << endl;

    return 0;
}



