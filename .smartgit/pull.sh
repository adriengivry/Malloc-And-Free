if [ -z "$1" ]
    then
        REMOTE="origin"
        echo "Selected remote : origin (By default)"
    else
        REMOTE=$1
        echo "Selected remote : $REMOTE"

fi

git pull $REMOTE master