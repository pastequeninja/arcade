/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeError.cpp
*/

#include "../../includes/Errors/ArcadeError.hpp"

arcade::ArcadeError::ArcadeError(const std::string &where, const std::string &what) :
_location(where), _message(what)
{}

const std::string &arcade::ArcadeError::where() const noexcept
{
    return _location;
}

const char *arcade::ArcadeError::what() const noexcept
{
    return _message.c_str();
}