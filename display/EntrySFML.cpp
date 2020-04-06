/*
** EPITECH PROJECT, 2022
** OOP_arcade_2019
** File description:
** Created by Zebens,
*/

#include "ModSFML.hpp"

__attribute__((constructor))
static void constsfml()
{
    arcade::IDisplayModule *sfml;
    std::cout << "[SFML lib] loading!" << std::endl;
    sfml = new arcade::SFMLclass();
}

__attribute__((destructor))
static void destsfml()
{
    std::cout << "[SFML lib] closing!" << std::endl;
    //mettre l'obj "sfml" en global ou autre moyen ?
    delete sfml;
}

extern "C" arcade::IDisplayModule *entryPoint(void)
{
    std::cout << "[SFML lib] Entry Point" << std::endl;
    //idem ou return new arcade::SFMLclass(); ?
    return sfml;
}