simon: main.c simon.h
	gcc -o simon -Wall main.c

install:
	make
	if [[ whoami != root ]]; then
		echo Install must be run as root.
	else
		cp simon /usr/bin/simon
		echo Simon installed!
	fi