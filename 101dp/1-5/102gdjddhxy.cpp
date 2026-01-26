#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int w[N], f[N];

int main() {
    int n, k;
    
    cin >> k;
    while (k --) {
        int res = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
        for (int i = 1; i <= n; i ++) {
            f[i] = 1;
            for (int j = 1; j < i; j ++) {
                if (w[j] < w[i]) f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        
        for (int i = n; i >= 1; i --) {
            f[i] = 1;
            for (int j = n; j > i; j --) {
                
                if (w[i] > w[j]) f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        
        cout << res << endl;
    }
    return 0;
}




