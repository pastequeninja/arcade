/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Arcade.cpp
*/

#include "Arcade.hpp"
#include "ArcadeError.hpp"
#include "event.hpp"
#include "LibParser.hpp"
#include <algorithm>
#include <LibLoader.hpp>

arcade::Arcade::Arcade(const std::string &glPath)
try : _selectGL(0), _selectGame(0), _pause(false), _disp(nullptr), _game(nullptr), _originPath(glPath)
{
    std::vector<std::string> GLPaths = LibParser::collectLibs(glPath);
    std::vector<std::string> GamesPaths = LibParser::collectLibs();
    _maxGL = GLPaths.size();
    _maxGame = GamesPaths.size();
    for (auto it = begin(GLPaths); it != end(GLPaths); it++) {
        if ((*it).substr(0, 6) == "./lib/")
            dispLibs.emplace_back(new LibLoader<IDisplayModule *>(*it));
        else
            dispLibs.emplace_back(new LibLoader<IDisplayModule *>("./lib/" + *it));
    }
    for (auto it = begin(GamesPaths); it != end(GamesPaths); it++) {
        gamesLibs.emplace_back(new LibLoader<IGameModule *>("./games/" + *it));
    }
    _disp = dispLibs[_selectGL]->load();
} catch (arcade::ArcadeError &e) {
    throw e;
}

arcade::Arcade::~Arcade()
{
     delete _disp;
     delete _game;
     for (unsigned i = 0; i < dispLibs.size(); i++)
         delete (dispLibs[i]);
     for (unsigned i = 0; i < gamesLibs.size(); i++)
         delete (gamesLibs[i]);
}

void arcade::Arcade::run()
{
    while (true) {
        event evt = _disp->getEvent();
        switch (evt) {
            case arcade::event::Quit:
                return;
            case arcade::event::Pause:
                _pause = !_pause;
                break;
            default:
                break;
        }
        if (_pause == false)
            _game->updateGame(evt);
        _disp->drawGameObjects(_game->getGameObjects());
    }
}

void arcade::Arcade::runMenu()
{
    std::vector<std::string> GLPaths = LibParser::collectLibs(_originPath);
    std::vector<std::string> GamesPaths = LibParser::collectLibs();
    bool isLeft = true;
    vector2<unsigned> selector = {0, 0};
    vector2<bool> areSelec = {false, false};
    bool runMenu = true;

    while (runMenu) {
        switch (_disp->getEvent()) {
            case arcade::event::Quit: return;
            case arcade::event::Up:
                if (isLeft == true) {
                    if (selector.x == 0)
                        selector.x = GamesPaths.size()-1;
                    else
                        selector.x--;
                } else {
                    if (selector.y == 0)
                        selector.y = GLPaths.size() -1;
                    else
                        selector.y--;
                }
                break;
            case arcade::event::Right:
                isLeft = false;
                break;
            case arcade::event::Left:
                isLeft = true;
                break;
            case arcade::event::Action2:
                if (isLeft == true) {
                    _selectGame = selector.x;
                    areSelec.x = true;
                } else {
                    _selectGL = selector.y;
                    areSelec.y = true;
                }
                break;
            case arcade::event::Action1:
                if (areSelec.x == false || areSelec.y == false)
                    break;
                else
                    runMenu = false;
            default : break;
        }
        _disp->drawMenu(GamesPaths, GLPaths);
    }
    load();
}

void arcade::Arcade::load()
{
    delete(_disp);
    _disp = dispLibs[_selectGL]->load();
    _game = gamesLibs[_selectGame]->load();
    run();
}