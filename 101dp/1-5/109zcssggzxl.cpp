#include <iostream>
#include <algorithm>


using namespace std;

const int N = 3010;

int a[N], b[N];
int f[N][N];

 // 优化代码
 // if (b[k] < b[j]) 中 a[i]=b[j] 用a[i]替换b[j]
 // k 循环变成 k=[1， j-1] 寻找 f[i - 1][1, j-1] + 1 的最大值 由于外面会对j进行1-n遍历  所以 获取最大值这一步可以拿出去
 // 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    
    for (int i = 1; i <= n; i ++) {
        int maxv = 1;  // f[i - 1][1, j-1] + 1 的最大值  最后需要得到 f[i][j] 的最大值 
        // f[i][j] 有两种请款 1. a[i] 不在公共上升子序列  2. a[i] 在公共上升子序列 由于b[j]被包含在序列中，所以有a[i]==b[j]
        for (int j = 1; j <= n; j ++) {
            f[i][j] = f[i - 1][j];  // 这里是 a[i] 不在公共上升子序列的情况
            if (a[i] == b[j])  f[i][j] = max(f[i][j], maxv);  // 只有存在时才更新 f[i][j]
            if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1);  // 这里是求最大值
        }
    }
        
    int res = 0;
    for (int i = 0; i <= n; i ++) res = max(res, f[n][i]);
    cout << res << endl;
    return 0;
}









// #include <iostream>
// #include <algorithm>


// using namespace std;

// const int N = 3010;

// int a[N], b[N];
// int f[N][N];


// int main() {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
//     for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);

//     for (int i = 1; i <= n; i ++) 
//         for (int j = 1; j <= n; j ++) {
//             f[i][j] = f[i - 1][j];  // 这里是 a[i] 不在公共上升子序列的情况
//             if (a[i] == b[j]) {  // 这里是a[i] 在公共子序列的情况
//                 // 如果 b[j] 是第一个元素 也就是j = 1 时，此时按理来说f[i][j] 等于1  
//                 f[i][j] = max(f[i][j], 1);  // 但是由于 首先执行了a[i]不在序列上的逻辑，直接赋值为1 会导致值被覆盖  可以试试 if (j == 1) f[i][j] = 1;
//                 for (int k = 1; k < j; k ++) {
//                     if (b[k] < b[j]) f[i][j] = max(f[i][j], f[i - 1][k] + 1);  
//                     // 由于这里的k时讨论的b[j] 前面的元素，由于a[i] 和 b[j] 是相等的，
//                     // 所以这里不能讨论a[i] 如果包含a[i]  所以应该是 a 中的i-1个数和b里面的k个数找最长，然后加上a[i] 这个值的1 就是当前最长的
//                 }
//             }
//         }
//     int res = 0;
//     for (int i = 0; i <= n; i ++) res = max(res, f[n][i]);
//     cout << res << endl;
//     return 0;
// }






