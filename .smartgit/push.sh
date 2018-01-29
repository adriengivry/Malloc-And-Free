if [ -z "$1" ]
    then
        MESSAGE="Oups, I forget to add a description to my commit"
    else
        MESSAGE=$1

fi

if [ -z "$2" ]
    then
        REMOTE="origin"
        echo "Selected remote : origin (By default)"
    else
        REMOTE=$2
        echo "Selected remote : $REMOTE"

fi

git add .
git commit -m "$MESSAGE"
git push $REMOTE master
git push $REMOTE master