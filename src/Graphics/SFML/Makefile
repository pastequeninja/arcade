##
## EPITECH PROJECT, 2020
## arcade
## File description:
## sfml makefile
##

LIBNAME	=	lib_arcade_sfml.so

GXX=	g++

ROOT_DIR=	../../..

CXXFLAGS=\
	-I.\
	-I..\
	-I$(ROOT_DIR)/includes\
	-W\
	-Wextra\
	-fPIC\
	-std=c++17\

LDFLAGS	=\
	-lsfml-graphics\
	-lsfml-window\
	-lsfml-system\
	-lsfml-audio

SRC	=\
	ModSFML.cpp\
	$(ROOT_DIR)/src/Errors/ArcadeError.cpp\

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
