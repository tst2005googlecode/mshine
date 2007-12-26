# Makefile for Moonshine core interpreter

# No arguments to Make builds for Unix-like systems
# Use "win" to build for Windows systems
msh:
	gcc -c -o msh.o msh.c
	gcc -o msh msh.o -Wl,--export-dynamic -L. -llua -lm -ldl
	rm -f msh.o
win:
	#gcc msh.c -o msh.exe lua5.1.dll

