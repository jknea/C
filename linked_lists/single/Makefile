# targets: prerequisites
#	command
#	command
#	command

# targets are file names, separated by spaces
# commands are steps used to make target(s), need to start with tabs
# prerequisites are also file names, separated by spaces.  Need to exist before commands for target are run

# all: two one main

# two: one
#	echo "This will always run, and runs second"
# one:
#	echo "This will always run, and runs first"

main: 
	gcc main.c sll.c -o a.out
	valgrind ./a.out

clean:
	echo "cleaning"
	rm -f a.out