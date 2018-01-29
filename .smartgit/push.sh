MESSAGE=$1

git add .
git commit -m MESSAGE
git push origin master
echo "Pushed worked like a charm !"