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


# https://www.linuxtoday.com/blog/analyzing-code-coverage-with-gcov/

main:
	gcc main.c dll.c -fprofile-arcs -ftest-coverage -o a.out
	valgrind ./a.out
	gcov dll.c main.c
	rm -f *.gcda *.gcov *.gcno

clean:
	echo "cleaning"
	rm -f a.out 