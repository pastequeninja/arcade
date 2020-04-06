/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#include "../../../includes/Graphics/ModNcurses.hpp"
#include "../../../includes/event.hpp"
#include <string.h>
#include <iostream>
#include <vector>
#include <curses.h>
#include "../../../includes/color.hpp"
#include "../../../includes/Errors/ArcadeError.hpp"
#include "../../../includes/vector2.hpp"
#include <unistd.h>
#include <stdbool.h>

#define DELAY 70000

int max_x_Window;
int max_y_Window;

extern "C" arcade::NCURSESclass *create()
{
  return (new arcade::NCURSESclass());
}

arcade::NCURSESclass::NCURSESclass()
{
    _Cursor_x = 49;
    _Cursor_y = 19;
    initscr();
    _Window = subwin(stdscr, LINES, COLS, 0, 0);
    _left_side = true;
    _current_game = 0;
    _current_lib = 0;
    curs_set(FALSE);
    _PopUp = subwin(stdscr, LINES / 2, COLS / 8, 0, 0);

    nodelay(stdscr, TRUE);
    noecho();

    //GAME//
    _GameWindow = subwin(stdscr, LINES / 2, COLS/4, 0, 0);
}

arcade::NCURSESclass::~NCURSESclass()
{}

void arcade::NCURSESclass::drawPlayer(const arcade::vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "O");
}

void arcade::NCURSESclass::drawEnd()
{}

void arcade::NCURSESclass::drawPlayer2(const arcade::vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "O");
}

void arcade::NCURSESclass::drawPlayerHit(const vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "O");
}

void arcade::NCURSESclass::drawWall(const arcade::vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "W");
}

void arcade::NCURSESclass::drawBonus(const arcade::vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "*");
}

void arcade::NCURSESclass::drawBonus2(const arcade::vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "*");
}

void arcade::NCURSESclass::drawEnemy(const arcade::vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "C");
}

void arcade::NCURSESclass::drawEnemy2(const arcade::vector2<unsigned> &pos)
{
    mvwprintw(_GameWindow, pos.y, pos.x, "C");
}

void arcade::NCURSESclass::move_cursor(std::vector<std::string> lib, std::vector<std::string> games)
{

    if (ev == KEY_RIGHT) {
        _left_side = false;
        _Cursor_x = 109;
        _Cursor_y = 19;
        _current_game = 0;
    }
    if (ev == KEY_LEFT) {
        _left_side = true;
        _Cursor_x = 49;
        _Cursor_y = 19;
        _current_lib = 0;
    }
    if ((_left_side) == false && ev == KEY_DOWN && ((_current_game) < (int)games.size() - 1)) {
        (_current_game)++;
        _Cursor_y += 2;
    }
    if ((_left_side) == false && ev == KEY_UP && ((_current_game) != 0)) {
        (_current_game)--;
        _Cursor_y -= 2;
    }
    if ((_left_side) == true && ev == KEY_DOWN && ((_current_lib) < (int)lib.size() - 1)) {
        (_current_lib)++;
        _Cursor_y += 2;
    }
    if ((_left_side) == true && ev == KEY_UP && ((_current_lib) != 0)) {
        (_current_lib)--;
        _Cursor_y -= 2;
    }
    if ((_left_side) == true && ev == '\n')
        _LibSelected = lib[(_current_lib)];
    if ((_left_side) == false && ev == '\n')
        _GameSelected = games[(_current_game)];
}

void arcade::NCURSESclass::drawMenu(const std::vector<std::string> &games, const std::vector<std::string> &libgraph)
{

    clear();
    if (LINES < 24 || COLS < 150) {
            mvprintw((LINES / 2), (COLS / 2) - (21 / 2), "window size too small");
        }
    else {
        _Window= subwin(stdscr, LINES, COLS, 0, 0);
        _PopUp = subwin(stdscr, LINES / 8, COLS / 2, 30, 45);
        box(_Window, ACS_VLINE, ACS_HLINE);
        box(_PopUp, ACS_VLINE, ACS_HLINE);
        drawText("MENU", vector2<unsigned int>(LINES / 4, COLS / 2));
        drawText(games[0], vector2<unsigned int>(LINES / 2 - 2, COLS / 1.4));
        drawText(games[1], vector2<unsigned int>(LINES / 2, COLS / 1.4));
        drawText(libgraph[0], vector2<unsigned int>(LINES / 2 - 2, COLS / 3));
        drawText(libgraph[1], vector2<unsigned int>(LINES / 2, COLS / 3));
        move_cursor(libgraph, games);
        mvprintw(_Cursor_y, _Cursor_x, "-- ");
        drawTextPopUp(vector2<unsigned int>(1, 1), "You selected game : " + _GameSelected, _PopUp);
        drawTextPopUp(vector2<unsigned int>(2, 1), "You will load your game with : " + _LibSelected, _PopUp);
        if (_GameSelected.size() != 0 && _LibSelected.size() != 0)
            drawTextPopUp(vector2<unsigned int>(3, 28), "PRESS SPACE TO START", _PopUp);
        doupdate();
    }
    usleep(DELAY);
}

const std::string &arcade::NCURSESclass::getName() const
{
    return _LibSelected;
}

void arcade::NCURSESclass::drawTextPopUp(const vector2<unsigned> pos, const std::string &data, WINDOW *window)
{
    char cstr[data.size() + 1];
    strcpy(cstr, data.c_str());

    mvwprintw(window, pos.x, pos.y, cstr);
}

void arcade::NCURSESclass::display()
{}


void arcade::NCURSESclass::drawText(const std::string &data, const vector2<unsigned> &pos)
{
    char cstr[data.size() + 1];
    strcpy(cstr, data.c_str());

    mvwprintw(_Window, pos.x, pos.y, cstr);
}

void arcade::NCURSESclass::drawGameObjects(const std::vector<arcade::GameObject> &g)
{
    clear();
    _GameWindow= subwin(stdscr, LINES, COLS / 2, 0, 0);
    for (auto it = g.begin(); it != g.end(); it++) {
        switch (it->type) {
            case arcade::GameObject::PLAYER: drawPlayer(it->pos);
                break;
            case arcade::GameObject::BONUS: drawBonus(it->pos);
                break;
            case arcade::GameObject::WALL: drawWall(it->pos);
            break;
            case arcade::GameObject::PLAYER2: drawPlayer2(it->pos);
            break;
            case arcade::GameObject::BONUS2: drawBonus2(it->pos);
            break;
            case arcade::GameObject::ENEMY2: drawEnemy2(it->pos);
            break;
            case arcade::GameObject::ENEMY: drawEnemy(it->pos);
            break;
            case arcade::GameObject::PLAYERHIT: drawPlayerHit(it->pos);
            break;
            default: break;
        }
    }
    refresh();
    usleep(DELAY);
}

arcade::arcade_events arcade::NCURSESclass::getEvent(void)
{
    keypad(stdscr, TRUE);
    ev = getch();
    switch(ev) {
        case KEY_UP:
            return arcade::arcade_events::Up;
        case KEY_DOWN:
            return arcade::arcade_events::Down;
        case KEY_RIGHT:
            return arcade::arcade_events::Right;
        case KEY_LEFT:
            return arcade::arcade_events::Left;
        case '\n':
            return arcade::arcade_events::Action2;
        case ' ':
            return arcade::arcade_events::Action1;
        case 'p':
            return arcade::event::Pause;
        case 'q':
            return arcade::arcade_events::Quit;
        case 'l':
            return arcade::event::SwitchGraphic;
        case 'g':
            return arcade::event::SwitchGame;
        case 'r':
            return arcade::event::Restart;
        default: return arcade::arcade_events::Nothing;
    }
    return arcade::arcade_events::Nothing;;
}


void arcade::NCURSESclass::refresh()
{
    doupdate();
}