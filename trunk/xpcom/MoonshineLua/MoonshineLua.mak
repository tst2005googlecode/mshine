#
#	Makefile for MoonshineLua for NMAKE on Windows
#

# PREQ: Visual Studio

# ASSUMPTION: devenv.exe is in your PATH

APP = MoonshineLua

make:
	devenv $(APP).sln /build Debug /project $(APP).vcproj /projectconfig Debug 
	
clean:
	devenv $(APP).sln /clean Debug /project $(APP).vcproj /projectconfig Debug 
