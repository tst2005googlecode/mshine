# Makefile for Moonshine core interpreter

# No arguments to Make builds for Unix-like systems
# Use "win" to build for Windows systems
msh: 
	gcc msh.c -o msh liblua.a -lm -ldl
win:
	gcc msh.c -o msh.exe lua5.1.dll
