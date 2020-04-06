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

        enum run_type
        {
            RUN, LEAVE, MENU
        };

    private:
        std::vector<std::unique_ptr<LibLoader<IDisplayModule *>>> dispLibs;
        std::vector<std::unique_ptr<LibLoader<IGameModule *>>> gamesLibs;
        unsigned _selectGL, _selectGame, _maxGL, _maxGame;
        bool _pause;
        IDisplayModule *_disp;
        IGameModule *_game;
        const std::string _originPath;
        enum run_type _rt;
    };
}

#endif //OOP_ARCADE_2019_ARCADE_HPP
