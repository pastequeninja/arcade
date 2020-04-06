/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGameModule.hpp
*/

#ifndef OOP_ARCADE_2019_IGAMEMODULE_HPP
#define OOP_ARCADE_2019_IGAMEMODULE_HPP

#include <list>
#include "GameObject.hpp"
#include "event.hpp"
#include <vector>

namespace arcade
{
    class IGameModule
    {
    public:
        virtual ~IGameModule() = 0;
        virtual void updateGame(const event &evt) = 0;
        virtual const std::vector<GameObject> &getGameObjects(void) const = 0;
        virtual void init(void) = 0; // ctor
        virtual void destroy(void) = 0; // dtor
    };
}

#endif //OOP_ARCADE_2019_IGAMEMODULE_HPP
