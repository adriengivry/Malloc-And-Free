################ SMARTGIT : How to use it #######################

--> Copy the .smartgit folder at the same level as the .git folder
--> Configure your remotes by modifying the remote.list
--> Use it by typing :
		bash .smartgit/push.sh [MESSAGE_IN_DOUBLE_QUOTES] [REMOTE_NAME_OR_'all']
		and
		bash .smartgit/pull.sh [REMOTE_NAME]


/!\ ATTENTION /!\
If you don't specify a remote, it will use the origin remote, even if you didn't wrote it in your remote list.
If you specify 'all' when you push, it will push on every remotes of your remote list (Don't forget to specify origin in the remote list).
You can add .bashrc aliases for push and pull commands, such as "smartpush" and "smartpull"

Example of command with aliases :
	smartpush "This is my commit" all
	smartpush all (Will push on every remotes with a default commit message)
	smartpush (will push on origin with a default commit message)
	smartpull work
	smartpull
