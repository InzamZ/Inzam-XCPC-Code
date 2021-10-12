#include <cstdio>
#include <iostream>
#include <sys/time.h>
//#include <windows.h>
#include <ctime>
using namespace std;

double get_wall_time()
{
    struct timeval time;
    if (gettimeofday(&time, NULL))
        return 0;
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
int main()
{
    double stdstart, stdstop, ystart, ystop;
    cout << "按下回车键开始对拍\n对拍100次后会暂停 任意键继续\nEnter....." << endl;
    getchar();
    for (int i = 1; i <= 1e7; i++) {
        system("./data");
        stdstart = get_wall_time();
        system("./std");
        stdstop = get_wall_time();
        ystart = get_wall_time();
        system("./yours");
        ystop = get_wall_time();
        if (system("diff std.out yours.out"))
            //if (system("fc std.out yours.out")) //windows
        {
            cout << i << ": Wrong Anwser!" << endl;
            printf("TIME: std:%8lf   yours:%8lf\n", stdstop - stdstart, ystop - ystart);
            cout << "请查看输入数据 \"in\" " << endl;
        }
        else {
            cout << "No. " << i << '\n'
                 << "OK!" << endl;
            printf("TIME: std:%8lf   yours:%8lf\n", stdstop - stdstart, ystop - ystart);
            getchar();
        }
        if (i % 100 == 0) {
            cout << "好累啊，休息一下\n试着加大数据？\n按任意键继续" << endl;
            getchar();
        }
    }
}