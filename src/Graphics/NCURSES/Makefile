##
## EPITECH PROJECT, 2020
## arcade
## File description:
## ncurses makefile
##

LIBNAME	=	lib_arcade_ncurses.so

GXX=	g++

CXXFLAGS=\
	-I.\
	-I..\
	-W\
	-Wextra\
	-fPIC\
	-std=c++17
LDFLAGS=\
	-lncurses

SRC	=\
	ModNcurses.cpp

OBJS=		$(SRC:%.cpp=%.o)

all:		$(LIBNAME)

$(LIBNAME):	$(OBJS)
			$(GXX) $(OBJS) -fPIC -shared -o $(LIBNAME) $(LDFLAGS)
			mv $(LIBNAME) ../../../lib/

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(LIBNAME)

re:		fclean all

.PHONY:		all clean fclean re
