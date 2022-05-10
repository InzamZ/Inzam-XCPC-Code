while true; do
    ./Ddata.out>tmp.in #出数据
    ./D.out<tmp.in>tmp.out #被测程序
    ./Dstd.out<tmp.in>tmp2.out #正确（暴力）程序
    if diff tmp.out tmp2.out; then #比较两个输出文件
        printf "AC\n"  #结果相同显示AC

    elif diff -B -b tmp.out tmp2.out; then
        printf "PE\n"

    else
        printf "WA\n" #结果不同显示WA，并退出
        exit 0
    fi
done