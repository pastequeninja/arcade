/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDLModule.hpp
*/

#ifndef OOP_ARCADE_2019_SDLMODULE_HPP
#define OOP_ARCADE_2019_SDLMODULE_HPP

#include "IDisplayModule.hpp"
#include "vector2.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define RATIO_GRID_W    30
#define RATIO_GRID_H    30

namespace arcade
{
    struct SDLMenuCursor
    {
        enum side {
            LEFT, RIGHT
        };
        vector2<unsigned> pos;
        enum side side;
        vector2<unsigned> max;
    };
    class SDLModule : public IDisplayModule
    {
    public:
        SDLModule();
        ~SDLModule() final;

        void drawRect(const arcade::vector2<> &pos, bool filled, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        void drawPlayer(const vector2<unsigned> &pos) final;
        void drawPlayer2(const vector2<> &pos) final;
        void drawPlayerHit(const vector2<unsigned> &pos) final;
        void drawWall(const arcade::vector2<unsigned> &pos) final;
        void drawBonus(const arcade::vector2<unsigned> &pos) final;
        void drawBonus2(const arcade::vector2<unsigned> &pos) final;
        void drawEnemy(const arcade::vector2<unsigned> &pos) final;
        void drawEnemy2(const arcade::vector2<unsigned> &pos) final;

        void drawText(const std::string &data, const vector2<unsigned> &pos) final;
        void drawGameObjects(const std::vector<GameObject> &go) final;
        void move_cursor(const std::vector<std::string> &gl, const std::vector<std::string> &games, std::string &lib, std::string &game);
        void drawMenu(const std::vector<std::string> &gamename, const std::vector<std::string> &displayname) final;
        const std::string &getName() const final;
        arcade::event getEvent(void) final;
        void refresh(void) final;
        void display() final;

    private:
        TTF_Font *_font;
        SDL_Event _evt;
        SDL_Window *_win;
        SDL_Renderer *_ren;
        SDL_Color _white, _black;
        const std::string _name;
        SDLMenuCursor cursor;
    };
}

#endif //OOP_ARCADE_2019_SDLMODULE_HPP
