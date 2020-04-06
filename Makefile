##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Unit tests
##

NAME    =       arcade

SRC_DIR	=	./src

ERR_DIR	=	$(SRC_DIR)/Errors

GL_DIR	=	$(SRC_DIR)/Graphics

GAME_DIR=	$(SRC_DIR)/Games

SOURCES	=\
	$(SRC_DIR)/Arcade.cpp\
	$(ERR_DIR)/ArcadeError.cpp\
	$(ERR_DIR)/DirectoryError.cpp\
	$(ERR_DIR)/InvalidLibrary.cpp\
	$(SRC_DIR)/LibParser.cpp\
	$(SRC_DIR)/LibLoader.cpp\
	$(SRC_DIR)/main.cpp\


OBJS	=	$(SOURCES:%.cpp=%.o)

CXXFLAGS=\
	-W\
	-Wextra\
	-Werror\
	-Iincludes\
	-Iincludes/Errors\
	-std=c++17\
	-fPIC\

LDFLAGS	=\
	-ldl\
	-lstdc++fs\

GXX	=	g++

all:
		make core -C .
		make graphicals -C .
		make games -C .

$(NAME):	$(OBJS)


core:		$(NAME)
		$(GXX) -o $(NAME) $(OBJS) $(LDFLAGS)

games:
		make -C $(GAME_DIR)

graphicals:
		make -C $(GL_DIR)

clean:
		$(RM) $(OBJS)
		make clean -C $(GL_DIR)
		make clean -C $(GAME_DIR)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(GL_DIR)
		make fclean -C $(GAME_DIR)
		$(RM) ./lib/*
		$(RM) ./games/*

re:             fclean all

debug:		CXXFLAGS += -g
debug:		re

.PHONY:		all core graphicals games clean fclean re debug
