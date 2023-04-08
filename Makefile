.POSIX:

include config.mk

#---------------------------------------------

all: optimise

#-----------------------------------------------

optimise:
	mkdir -p ./distribution
	g++   ./source/$(NAME_PROGRAM).c++ $(C_FLAGS) $(C_LIBS) -o ./distribution/$(NAME_PROGRAM)

build:
	mkdir -p ./distribution
	g++   ./source/$(NAME_PROGRAM).c++ $(C_FLAGS) $(C_EXTRA) $(C_LIBS) -o ./distribution/$(NAME_PROGRAM)

test:
	./Testador.zsh $(NAME_PROGRAM)

.PHONY: all build optimise
