/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake game
*/

#include "vector2.hpp"

#ifndef MAP_HPP_
#define MAP_HPP_

namespace arcade {
    enum class ObjectType : int {
        BONUS = 0,
        OBSTACLE = 1,
        PLAYER = 2,
        PLAYER2 = 3,
        BACKGROUND = 4,
    };
    struct getmap {
        int width;
        int height;
        ObjectType object;
        vector2<int> *pos;
        struct getmap *next;
        struct getmap *prev;
    };
}

#endif