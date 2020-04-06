##
## EPITECH PROJECT, 2020
## arcade
## File description:
## sdl makefile
##

NAME	=	lib_arcade_sdl.so

SRCS	=	SDLModule.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

CXXFLAGS=\
	-W\
	-Wextra\
	-Werror\
	-I../../../includes\
	-std=c++17\
	-fPIC\

SDLFLAGS=\
	-lSDL2\
	-lSDL2_ttf\

GXX	=	g++

all:		$(NAME)

$(NAME):	$(OBJS)
		$(GXX) -o $(NAME) $(OBJS) $(SDLFLAGS) -fPIC -shared
		mkdir -p ../../../lib
		mv $(NAME) ../../../lib

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
