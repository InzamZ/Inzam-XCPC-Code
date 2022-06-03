$c=0
$d=0
$filesize1=0
$filesize2=0

clear
echo "Input File Name: "
read file1

if [ -e $file1 ]
then
    filesize1=`ls -l $file1 | awk '{print $5}'`
    echo "Currect status of $file1 is :"
    ls -l $file1
    while [ 1 ]
    do
        echo ""
        echo "test file's status..."
        sleep 1
        filesize2=`ls -l $file1 | awk '{print $5}'`
        if [[ $filesize1 == $filesize2 ]]
        then
            echo "File is not changed"
        else
            echo "file [$file1] size changed"
            filesize1=$filesize2
            c=$c+1
        fi
        if [[ $c -eq 2 ]]
        then
            echo ""
            echo "Changed number exceed 2 times, test end!"
            break
        fi
        d=$d+1
        if [[ $d -eq 10 ]]
        then
            echo ""
            echo "Test number exceed 10 , test end!"
            break
        fi
        sleep 3
    done
else
    echo "File Not Found"
fi