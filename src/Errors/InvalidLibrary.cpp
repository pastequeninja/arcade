/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** InvalidLibrary.cpp
*/

#include "InvalidLibrary.hpp"

arcade::InvalidLibrary::InvalidLibrary(const std::string &where, const std::string &what) :
ArcadeError(where, what)
{}