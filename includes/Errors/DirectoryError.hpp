/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DirectoryError.hpp
*/

#ifndef OOP_ARCADE_2019_DIRECTORYERROR_HPP
#define OOP_ARCADE_2019_DIRECTORYERROR_HPP

#include "ArcadeError.hpp"

namespace arcade
{
    class DirectoryError : public ArcadeError
    {
    public:
        DirectoryError(const std::string &where, const std::string &what);
    };
}

#endif //OOP_ARCADE_2019_DIRECTORYERROR_HPP
