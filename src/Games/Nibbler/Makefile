##
## EPITECH PROJECT, 2020
## arcade
## File description:
## sfml makefile
##

LIBNAME	=	lib_arcade_nibbler.so

GXX=	g++

CXXFLAGS=\
	-I.\
	-I..\
	-W\
	-Wextra\
	-Werror\
	-fPIC\
	-std=c++17

SRC	=\
	src/Snake.cpp

OBJS=		$(SRC:%.cpp=%.o)

all:		$(LIBNAME)

$(LIBNAME):	$(OBJS)
		$(GXX) $(OBJS) -fPIC -shared -o $(LIBNAME)
		mv $(LIBNAME) ../../../games

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(LIBNAME)

re:		fclean all

.PHONY:		all clean fclean re
