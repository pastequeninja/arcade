/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#include <algorithm>
#include <signal.h>
#include "../IDisplayModule.hpp"
#include "../color.hpp"
#include <ncurses.h>
#include "../event.hpp"
#include <form.h>
#include "../Errors/ArcadeError.hpp"

#ifndef MOD_NCURSES_HPP_
#define MOD_NCURSES_HPP_

//extern "C" arcade::IDisplayModule create();

namespace arcade {
        class NCURSESclass : public arcade::IDisplayModule {
            private:
                WINDOW *_Window;
                WINDOW *_PopUp;
                WINDOW *_GameWindow;
                int _Window_X;
                int _Window_Y;
                std::string _LibSelected;
                std::string _GameSelected;
                int _current_game;
                int _current_lib;
                bool _left_side;
                int ev;
                int _Score;
                arcade::event _LastCommand;

                int _Cursor_x;
                int _Cursor_y;

            public:
            NCURSESclass();
            ~NCURSESclass() final;
            void drawPlayer(const vector2<unsigned> &) final;
            void drawPlayer2(const vector2<unsigned> &) final;
            void drawPlayerHit(const vector2<unsigned> &) final; //se fail
            void drawWall(const arcade::vector2<unsigned> &) final;
            void drawBonus(const arcade::vector2<unsigned> &) final;
            void drawBonus2(const arcade::vector2<unsigned> &) final;
            void drawEnemy(const arcade::vector2<unsigned> &) final;
            void drawEnemy2(const arcade::vector2<unsigned> &) final;
            void drawGameObjects(const std::vector<GameObject> &go) final;
            void drawMenu(const std::vector<std::string> &gamename, const std::vector<std::string> &display) final;
            void drawEnd() final;
            arcade_events getEvent(void) final;
            const std::string &getName() const final;
            void refresh(void) final;
            void drawText(const std::string &data, const vector2<unsigned> &pos) final;
            void display() final;
            
            void move_cursor(std::vector<std::string>, std::vector<std::string>);
            void drawTextPopUp(const vector2<unsigned> pos, const std::string &data, WINDOW *window);

        };
}

#endif