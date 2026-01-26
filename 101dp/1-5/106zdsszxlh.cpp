#include <iostream>
#include <algorithm>


using namespace std;


const int N = 1010;

int f[N], w[N];

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        f[i] = w[i];
        for (int j = 1; j < i; j ++) 
            if (w[j] < w[i]) f[i] = max(f[i], f[j] + w[i]);
        res = max(res, f[i]);
    }
    cout << res << endl;
    return 0;
}


