/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main.cpp
*/

#include "Arcade.hpp"
#include "ArcadeError.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr
                << "Invalid number of argument - a path to a graphical library is needed."
                << std::endl;
        return 84;
    }
    try {
        arcade::Arcade Core(av[1]);
        Core.runMenu();
    } catch (const arcade::ArcadeError &e) {
        std::cerr << e.where() << " : " << e.what() << std::endl;
        return 84;
    }
    return 0;
}