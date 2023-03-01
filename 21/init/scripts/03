#!/bin/bash

if [ -z $1 ]; then
	perl -E 'say "\033[31m"'
	echo "usage: empty parameter"
	echo "use -h or --help to get help"
	exit 0
fi

case $1 in
	"-h" | "--help")
		perl -E 'say "\033[36m"'
		echo "-h | --help"
		echo "	get help message"
		echo "-s | --status:"
		echo "	get repository status"
		echo "-p | --pull"
		echo "	pull commits"
		echo "-a | --add <file>"
		echo "	add file to git"
		echo "-r | --remove <file>"
		echo "	remove file from git"
		echo "-c | --commit <message>"
		echo "	commit and push"
		echo "-ac <file> <message>"
		echo "	add & commit & push"
		echo "-rc <file> <message>"
		echo "	rm & commit & push"
	;;
	"-s" | "--status")
		perl -E 'say "\033[36m"'
		git status
	;;
	"-p" | "--pull")
		git pull
	;;
	"-a" | "--add")
		if [ -z $2 ]; then
			git add --all
		else
			git add $2
		fi
	;;
	"-r" | "--remove")
		if [ -z $2 ]; then
			echo "usage: empty parameter"
			echo "use: ggit -r <file> <commit>"
		else
			git rm $2
		fi
	;;
	"-c" | "--commit")
		if [ -z $2 ]; then
			git commit -m "default commit messege"
		else
			git commit -m "$2"
		fi
		git push
		perl -E 'say "\033[32m"'
		git status
	;;
	"-ac")
		if [ -z $2 ]; then
			git add --all
			git commit -m "default commit messege"
		else
			git add $2
			if [ -z $3 ]; then
				git commit -m "default commit messege"
			else
				git commit -m "$3"
			fi
		fi
		git push
		perl -E 'say "\033[32m"'
		git status
	;;
	"-rc")
		if [ -z $2 ]; then
			echo "usage: empty parameter"
			echo "use: ggit -r <file> <commit>"
		else
			git rm $2
			if [ -z $3 ]; then
				git commit -m "default commit messege"
			else
				git commit -m "$3"
			fi
		fi
		git push
		perl -E 'say "\033[32m"'
		git status
	;;
	*)
		perl -E 'say "\033[31m"'
		echo "usage: unknown parameter"
		echo "use -h or --help to get help"
	;;
esac
perl -E 'say "\033[0m"'

exit 0
