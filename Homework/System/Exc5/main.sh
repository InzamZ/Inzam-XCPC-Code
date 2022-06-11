if [ $# -le 0 ]; then
    echo "Usage: usr monitor username"
    exit 0;
fi
user=$1

while [ true ]; do
    userlist=`who|awk '{print $1}'`
    for usrtmp in ${userlist} ; do
        if [ ${usrtmp} = ${user} ]; then
            echo "user [${user}] is login" 
            exit 0;
        fi
    done
    echo "waiting user [${user}]"
    sleep 5
done


