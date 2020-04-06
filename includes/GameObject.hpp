/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject.hpp
*/

#ifndef OOP_ARCADE_2019_GAMEOBJECT_HPP
#define OOP_ARCADE_2019_GAMEOBJECT_HPP

#include "vector2.hpp"

namespace arcade
{
    struct GameObject {
        enum type : unsigned int {
            PLAYER, PLAYER2, PLAYERHIT, WALL, BONUS, BONUS2, ENEMY, ENEMY2
        };

        GameObject::type type;
        vector2<unsigned> pos;
    };
}

#endif //OOP_ARCADE_2019_GAMEOBJECT_HPP
