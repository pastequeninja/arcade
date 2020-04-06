/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDLModule.cpp
*/

#include "SDLModule.hpp"
#include <algorithm>
#include <vector>

arcade::SDLModule::SDLModule() : _white({255, 255, 255, 255}), _black({0, 0, 0, 255}), _name("SDL")
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 || TTF_Init() != 0)
        return;
    _font = TTF_OpenFont("./medias/arial.ttf", 30);
    _win = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, SDL_WINDOW_SHOWN);
    _ren = SDL_CreateRenderer(_win, -1, 0);

    cursor.pos.x = 3;
    cursor.pos.y = 5;
    cursor.side = arcade::SDLMenuCursor::LEFT;
}

arcade::SDLModule::~SDLModule()
{
    TTF_CloseFont(_font);
    SDL_DestroyRenderer(_ren);
    SDL_DestroyWindow(_win);
}

void arcade::SDLModule::drawRect(const arcade::vector2<> &pos, bool filled, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Rect rec = {(int)pos.x * RATIO_GRID_W, (int)pos.y * RATIO_GRID_H, RATIO_GRID_W, RATIO_GRID_H};

    SDL_SetRenderDrawColor(_ren, r, g, b, a);
    if (filled)
        SDL_RenderFillRect(_ren, &rec);
    else
        SDL_RenderDrawRect(_ren, &rec);
    SDL_SetRenderDrawColor(_ren, 0, 0, 0, 255);
}

void arcade::SDLModule::drawPlayer(const vector2<> &pos)
{
    drawRect(pos, true, 0, 255, 255, 255);
}

void arcade::SDLModule::drawPlayer2(const vector2<> &pos)
{
    drawRect(pos, false, 0, 255, 255, 255);
}

void arcade::SDLModule::drawPlayerHit(const vector2<> &pos)
{
    drawRect(pos, true, 255, 0, 255, 255);
}

void arcade::SDLModule::drawWall(const arcade::vector2<> &pos)
{
    drawRect(pos, true, 128, 0, 0, 255);
}

void arcade::SDLModule::drawBonus(const arcade::vector2<> &pos)
{
    drawRect(pos, true, 0, 255, 125, 255);
}

void arcade::SDLModule::drawBonus2(const arcade::vector2<> &pos)
{
    drawRect(pos, true, 255, 255, 0, 255);
}

void arcade::SDLModule::drawEnemy(const arcade::vector2<> &pos)
{
    drawRect(pos, true, 255, 0, 0, 255);
}

void arcade::SDLModule::drawEnemy2(const arcade::vector2<unsigned int> &pos)
{
    drawRect(pos, false, 255, 0, 0, 255);
}

void arcade::SDLModule::drawText(const std::string &data, const vector2<unsigned> &pos)
{
    SDL_Surface *sT = TTF_RenderText_Solid(_font, data.c_str(), _white);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(_ren, sT);
    int texW, texH = 0;
    SDL_QueryTexture(tex, nullptr, nullptr, &texW, &texH);
    SDL_Rect dsrect = {(int)pos.x * RATIO_GRID_W, (int)pos.y * RATIO_GRID_H, texW, texH};

    SDL_RenderCopy(_ren, tex, nullptr, &dsrect);

    SDL_DestroyTexture(tex);
    SDL_FreeSurface(sT);
}

void arcade::SDLModule::drawGameObjects(const std::vector<GameObject> &go)
{
    refresh();
    std::for_each(begin(go), end(go), [&] (const GameObject &obj) {
        switch (obj.type) {
            case GameObject::PLAYER: drawPlayer(obj.pos); break;
            case GameObject::PLAYER2: drawPlayer2(obj.pos); break;
            case GameObject::PLAYERHIT: drawPlayerHit(obj.pos); break;
            case GameObject::WALL: drawWall(obj.pos); break;
            case GameObject::BONUS: drawBonus(obj.pos); break;
            case GameObject::BONUS2: drawBonus2(obj.pos); break;
            case GameObject::ENEMY: drawEnemy(obj.pos); break;
            case GameObject::ENEMY2: drawEnemy2(obj.pos); break;
            default: break;
        }
    });
    display();
}

void arcade::SDLModule::move_cursor(const std::vector<std::string> &gl, const std::vector<std::string> &games, std::string &lib, std::string &game)
{
    switch (_evt.type) {
        case SDL_KEYDOWN: break;
        case SDL_KEYUP:
            switch (_evt.key.keysym.sym) {
                case SDLK_DOWN:
                    if (cursor.side == SDLMenuCursor::LEFT) {
                        if (cursor.pos.y != cursor.max.x)
                            cursor.pos.y += 2;
                    } else {
                        if (cursor.pos.y != cursor.max.y)
                            cursor.pos.y += 2;
                    }
                    break;
                case SDLK_UP:
                    if (cursor.side == SDLMenuCursor::LEFT) {
                        if (cursor.pos.y != 5)
                            cursor.pos.y -= 2;
                    } else {
                        if (cursor.pos.y != 5)
                            cursor.pos.y -= 2;
                    }
                    break;
                case SDLK_RIGHT:
                    if (cursor.side == SDLMenuCursor::LEFT) {
                        cursor.pos.x = 16;
                        cursor.side = SDLMenuCursor::RIGHT;
                        while (cursor.pos.y > cursor.max.y)
                            cursor.pos.y -= 2;
                    }
                    break;
                case SDLK_LEFT:
                    if (cursor.side == SDLMenuCursor::RIGHT) {
                        cursor.pos.x = 3;
                        cursor.side = SDLMenuCursor::LEFT;
                        while (cursor.pos.y > cursor.max.x)
                            cursor.pos.y -= 2;
                    }
                    break;
                case SDLK_RETURN:
                    if (cursor.side == SDLMenuCursor::RIGHT) {
                        lib = gl[(cursor.pos.y - 5) / 2];
                    } else {
                        game = games[(cursor.pos.y - 5) / 2];
                    }
                    break;
                default: break;
            }
            break;
        default: break;
    }
}

void arcade::SDLModule::drawMenu(const std::vector<std::string> &games, const std::vector<std::string> &gl)
{
    refresh();
    cursor.max.x = 5 + 2 * (games.size()-1);
    cursor.max.y = 5 + 2 * (gl.size()-1);
    static std::string lib = "";
    static std::string game = "";
//    std::cout << "cursor y: " << cursor.pos.y << std::endl;
    //create box
//    std::cout << "LIB " << lib << " | GAME " << game << std::endl;
    drawText("MENU ARCADE", vector2<>(14, 1));
    for (unsigned i = 0; i < games.size(); i++)
        drawText(games[i], vector2<unsigned>(5, 5 + i * 2));
    for (unsigned i = 0; i < gl.size(); i++)
        drawText(gl[i], vector2<unsigned>(18, 5 + i * 2));
    move_cursor(gl, games, lib, game);
    drawRect(cursor.pos, false, 255, 255, 255, 255);

    drawText("[ " + game + " + " + lib + " ]", vector2<unsigned>(5, 25));
    drawText("Enter to select, Space to start when ready.", vector2<unsigned>(2, 28));
    //block selector
    display();
}

void arcade::SDLModule::drawEnd()
{
}

const std::string &arcade::SDLModule::getName() const
{
    return _name;
}

arcade::event arcade::SDLModule::getEvent()
{
//    SDL_Event evt;
//
    if (SDL_PollEvent(&_evt)) {
        switch (_evt.type) {
            case SDL_WINDOWEVENT:
                if (_evt.window.event == SDL_WINDOWEVENT_CLOSE)
                    return Quit;
                return Nothing;
            case SDL_KEYUP:
                switch (_evt.key.keysym.sym) {
                    case SDLK_UP: return Up;
                    case SDLK_DOWN: return Down;
                    case SDLK_RIGHT: return Right;
                    case SDLK_LEFT: return Left;
                    case SDLK_SPACE: return Action1;
                    case SDLK_RETURN: return Action2;
                    case SDLK_p: return Pause;
                    case SDLK_r: return Restart;
                    case SDLK_m: return Menu;
                    case SDLK_q: return Quit;
                    case SDLK_l: return SwitchGraphic;
                    case SDLK_g: return SwitchGame;
                    default: return Nothing;
                }
            default: return Nothing;
        }
    } else
        _evt.type = SDL_KEYDOWN;
        return Nothing;
}

void arcade::SDLModule::refresh()
{
    SDL_RenderClear(_ren);
}

void arcade::SDLModule::display()
{
    SDL_RenderPresent(_ren);
}

extern "C" {
    arcade::IDisplayModule *create()
    {
        return new arcade::SDLModule();
    }
}