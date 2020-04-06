/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Arcade.hpp
*/

#ifndef OOP_ARCADE_2019_ARCADE_HPP
#define OOP_ARCADE_2019_ARCADE_HPP

#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "LibLoader.hpp"
#include <vector>
#include <memory>

namespace arcade
{
    class Arcade
    {
    public:
        Arcade(const std::string &glPath);
        ~Arcade();
        void run();
        void load();
        void runMenu();

    private:
        std::vector<LibLoader<IDisplayModule *> *> dispLibs;
        std::vector<LibLoader<IGameModule *> *> gamesLibs;
        unsigned _selectGL, _selectGame, _maxGL, _maxGame;
        bool _pause;
        IDisplayModule *_disp;
        IGameModule *_game;
        const std::string _originPath;
    };
}

#endif //OOP_ARCADE_2019_ARCADE_HPP
