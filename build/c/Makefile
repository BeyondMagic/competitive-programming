.POSIX:

include config.mk

#---------------------------------------------

all: optimise

#-----------------------------------------------

optimise:
	$(COMPILER) $(NAME_PROGRAM)/$(FILE) $(FLAGS) $(LIBS) -o $(NAME_PROGRAM)/binary

build:
	$(COMPILER) $(NAME_PROGRAM)/$(FILE) $(FLAGS) $(EXTRA) $(LIBS) -o $(NAME_PROGRAM)/binary

.PHONY: all build optimise
