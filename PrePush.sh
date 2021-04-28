echo "Try to remove the executable file and sort out the I/O data"

cnt_rm_x_file=0
cnt_rm_in_file=0
cnt_rm_out_file=0
# 循环每个目录
for dir1 in `ls ./`
do
    if test -d $dir1 #判断是否为目录
    then
        cd ./$dir1
        echo "Working in $dir1 ... "
        for file in `ls ./`
        do
            if test -x $file #删除可执行文件
            then
                printf "rm -f $file \n"
                cnt_rm_x_file= `expr $cnt_rm_x_file + 1`
            elif test $file -eq *.in
            then 
                if [ ! -d ./data]
                then
                    mkdir data
                fi
                mv -u $file ./data 
                cnt_rm_in_file= `expr $cnt_rm_in_file + 1`
            elif test $file -eq *.out
            then 
                if [ ! -d ./data]
                then
                    mkdir data
                fi
                mv -u $file ./data
                cnt_rm_out_file= `expr $cnt_rm_out_file + 1`
            fi
        done
        cd ..
        printf "Done\n"
    fi
done

printf "Finished!\nRemoved %d executable files!\nSorted out %d \".in\" files and %d \".out\" files!\n" $cnt_rm_x_file $cnt_rm_in_file $cnt_rm_out_file
        