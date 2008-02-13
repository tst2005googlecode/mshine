# Makefile for Moonshine core interpreter

# No arguments to Make builds for Unix-like systems
# Use "mingw" to build for Windows systems

# compilers
CC1 = gcc 
CC2 = g++ 

# libraries
LIB1 = lua
LIB2 = lua5.1.dll

# executables
EXE1 = msh
EXE2 = mshcpp

msh:
	${CC1} -c -o msh.o msh.c
	${CC1} -o ${EXE1} msh.o -Wl,--export-dynamic -L. -l${LIB1} -lm -ldl
	${CC2} -c -o msh.o msh.cpp
	${CC2} -o ${EXE2} msh.o -Wl,--export-dynamic -L. -l${LIB1} -lm -ldl
	rm -f msh.o
mingw:
	${CC1} msh.c -o ${EXE1}.exe ${LIB2}
	${CC2} msh.cpp -o ${EXE2}.exe ${LIB2}

