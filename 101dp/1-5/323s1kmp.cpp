#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;
int n, m, ne[N];
char s[M], p[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;
    // 先求 next 数组  
    // ne[1] = 0  因为 如果模板第一个字符（下标是1） 与 当前的 i 不匹配 则需要去匹配下一个 i ， j = ne[j] 之后 j = 0这是后不满足while 循环 就跳出了
    for (int i = 2, j = 0; i <= n; i ++) {
        while(j && p[i] != p[j + 1]) j = ne[j]; // 找 前缀中最后一个字符t与后缀中最后一个字符i相等的那个 t的下标
        if (p[i] == p[j + 1]) j ++;  // 相等那么有 以i为终点的串与串的前缀 最长匹配可以加1 因为j + 1 是前缀的最后一个 i 是后缀 的最后一个
        ne[i] = j;  // 以 i 为终点的后缀 与 模板串前缀最长相等长度是 j  后续使用模板串匹配时
        // 这里 后面i没匹配上之后 可以通过回到j指示的位置  因为这一句的j是指匹配的前缀中最后一个字符
        
    }
    for (int i = 1, j = 0; i <= m; i ++) {
        while (j && s[i] != p [j + 1]) j = ne[j];
        if (s[i] == p [j + 1]) j ++;
        if (j == n) {
            printf("%d ", i - n);  // 这里题目里面是从0开始算的 所以这里不加1就是答案
            j = ne[j];  // 匹配下一个地方
        }
    }
    return 0;
}



