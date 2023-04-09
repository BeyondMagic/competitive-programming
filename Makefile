.POSIX:

include config.mk

#---------------------------------------------

all: optimise

#-----------------------------------------------

optimise:
	g++   ./$(NAME_PROGRAM)/source.c++ $(C_FLAGS) $(C_LIBS) -o ./$(NAME_PROGRAM)/binary

build:
	g++   ./$(NAME_PROGRAM)/source.c++ $(C_FLAGS) $(C_EXTRA) $(C_LIBS) -o ./$(NAME_PROGRAM)/binary

.PHONY: all build optimise
