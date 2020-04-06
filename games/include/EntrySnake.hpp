/*
** EPITECH PROJECT, 2022
** OOP_arcade_2019
** File description:
** Created by Zebens,
*/

#include "Snake.hpp"

__attribute__((constructor))
static void constsnake()
{
    arcade::IGameModule *snake;
    std::cout << "[Snake game] loading!" << std::endl;
    snake = new arcade::snake();
}

__attribute__((destructor))
static void destsnake()
{
    std::cout << "[Snake game] closing!" << std::endl;
    //mettre l'obj "sfml" en global ou autre moyen ?
    delete snake;
}

extern "C" arcade::IGameModule *entryPoint(void)
{
    std::cout << "[Snake game] Entry Point" << std::endl;
    //idem ou return new arcade::SFMLclass(); ?
    return snake;
}