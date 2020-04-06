/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** InvalidLibrary.hpp
*/

#ifndef OOP_ARCADE_2019_INVALIDLIBRARY_HPP
#define OOP_ARCADE_2019_INVALIDLIBRARY_HPP

#include "ArcadeError.hpp"

namespace arcade
{
    class InvalidLibrary : public ArcadeError
    {
    public:
        InvalidLibrary(const std::string &where, const std::string &what);
    };
}

#endif //OOP_ARCADE_2019_INVALIDLIBRARY_HPP
