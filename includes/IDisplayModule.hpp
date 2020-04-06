/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplayModule.hpp
*/

#ifndef OOP_ARCADE_2019_IDISPLAYMODULE_HPP
#define OOP_ARCADE_2019_IDISPLAYMODULE_HPP

#include <string>
#include <vector>
#include "vector2.hpp"
#include "event.hpp"
#include "color.hpp"
#include "GameObject.hpp"

namespace arcade
{
    class IDisplayModule
    {
    public:
        virtual ~IDisplayModule() {};

        virtual void drawPlayer(const vector2<unsigned> &pos) = 0;
        virtual void drawPlayer2(const vector2<unsigned> &pos) = 0;
        virtual void drawPlayerHit(const vector2<unsigned> &pos) = 0;
        virtual void drawWall(const arcade::vector2<unsigned> &pos) = 0;
        virtual void drawBonus(const arcade::vector2<unsigned> &pos) = 0;
        virtual void drawBonus2(const arcade::vector2<unsigned> &pos) = 0;
        virtual void drawEnemy(const arcade::vector2<unsigned> &pos) = 0;
        virtual void drawEnemy2(const arcade::vector2<unsigned> &pos) = 0;

        virtual void drawText(const std::string &data, const vector2<unsigned> &pos) = 0;
        virtual void drawGameObjects(const std::vector<GameObject> &go) = 0;
        virtual void drawMenu(const std::vector<std::string> &gamename, const std::vector<std::string> &displayname) = 0;
        virtual const std::string &getName() const = 0;
        virtual arcade::arcade_events getEvent(void) = 0;
        virtual void refresh(void) = 0;

    private:
        virtual void display() = 0;
    };
}

#endif //OOP_ARCADE_2019_IDISPLAYMODULE_HPP
