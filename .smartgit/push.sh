#!/bin/bash

if [ -z "$1" ]
    then
        MESSAGE="Oups, I forget to add a description to my commit"
    else
        MESSAGE=$1
fi

git add .
git commit -m "$MESSAGE"
echo "Commit done with message : $MESSAGE"

if [ "$2" == "all"]; 
    then
        echo "Okey, let's push on every remotes"
        while IFS='' read -r LINE || [[ -n "$LINE" ]]; 
            do
                git push $LINE master
                echo "Pushed on remote : $LINE"
        done < ".smartgit/remote.list"
        
    else
        if [ -z "$2" ]
            then
                REMOTE="origin"
                echo "Selected remote : origin (By default)"
            else
                REMOTE=$2
                echo "Selected remote : $REMOTE"

        fi
        git push $REMOTE master
fi