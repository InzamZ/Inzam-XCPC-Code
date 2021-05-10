#include<stdio.h>
struct mode {
    int L, R;
    int num;
} a[2000]; //结构体，L，R分别是a[i]的左边和右边的数，a[i].num是a[i]本身的值
void Move(int stap, int x, int y)
{
    if (stap == 1) { //模式1（将x移向y的左边）
        a[a[x].R].L = a[x].L; //x的右边的左边等于x原来的左边
        a[a[x].L].R = a[x].R; //x的左边的右边等于x原来的右边
        a[x].L = a[y].L; //x的左边等于y原来的左边
        a[a[y].L].R = a[x].num; //y原来的左边的右边变成x
        a[x].R = a[y].num; //x的右边变成y
        a[y].L = a[x].num; //y的左边变成x
        return;
    }
    else if (stap == 2) { //模式2（将x移向y的右边）
        a[a[x].R].L = a[x].L; //x的右边的左边等于x原来的左边
        a[a[x].L].R = a[x].R; //x左边的右边等于x原来的右边
        a[y].L = a[x].R; //y的左边等于x原来的右边
        a[x].L = a[y].num; //x的左边等于y
        a[x].R = a[y].R; //x的右边等于y原来的右边
        a[y].R = a[x].num; //y的右边等于x
        return;
    }
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("std.out", "w", stdout);
    int i, j, n, sum, m, stap, x, y, k, first, b, pre = 0;
    scanf("%d%d", &sum, &m);
    for (i = 1; i <= sum; i++) { //初始化数组
        scanf("%d", &b);
        a[i].num = i;
        a[i].L = i - 1;
        a[i].R = i + 1;
    }
    a[pre].R = sum + 1;
    while (m--) {
        scanf("%d %d %d", &stap, &x, &y);
        Move(stap, x, y); //进行调换
    }
    for (i = 1; i <= sum; i++) {
        if (a[i].L == 0) //谁的左边是0，谁第一个输出
            first = i; //标记第一个输出的数
    }
    k = 0;
    while (k <= sum) {
        if (k == 0) { //第一次输出
            //不输出左边的0（因为原来就没有o）
            printf("%d ", a[first].num);
            printf("%d ", a[first].R);
            k += 3; //下次的那个数没有计算，这里要加3而不是2
            first = a[first].R;
        }
        else {
            printf("%d ", a[first].R);
            k++;//每输出一个数k加一次，知道k满足数组的长度退出
            first = a[first].R;
        }
    }
    printf("\n");
    return 0;
}