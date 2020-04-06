/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake game
*/

#include "../include/Snake.hpp"
#include "../../../../includes/event.hpp"
#include "../../../../includes/Errors/ArcadeError.hpp"
#include "../../../../includes/GameObject.hpp"
#include <cstdlib>

extern "C" {
    arcade::snake *create()
    {
      return (new arcade::snake());
    }
}
arcade::snake::snake()
{
    GameObject snake_head;
    GameObject apple;
    GameObject wall;

    snake_head.pos = vector2<unsigned int>(20, 20);
    apple.pos = vector2<unsigned int>(10, 10);
    for (int i = 0; i < 20; i++) {
        wall.pos = vector2<unsigned int>(i, 0);
        wall.type = GameObject::WALL;
        _SnakeGO.push_back(wall);
    }
    for (int i = 0; i < 20; i++) {
        wall.pos = vector2<unsigned int>(0, i);
        wall.type = GameObject::WALL;
        _SnakeGO.push_back(wall);
    }
    for (int i = 0; i < 20; i++) {
        wall.pos = vector2<unsigned int>(0, i);
        wall.type = GameObject::WALL;
        _SnakeGO.push_back(wall);
    }
    for (int i = 0; i < 20; i++) {
        wall.pos = vector2<unsigned int>(20, i);
        wall.type = GameObject::WALL;
        _SnakeGO.push_back(wall);
    }
    for (int i = 0; i < 20; i++) {
        wall.pos = vector2<unsigned int>(i, 20);
        wall.type = GameObject::WALL;
        _SnakeGO.push_back(wall);
    }
    snake_head.type = GameObject::PLAYER;
    apple.type = GameObject::BONUS;
    _SnakeGO.push_back(snake_head);
    _SnakeGO.push_back(apple);
    _SnakeEvent = arcade::event::Up;
}
arcade::snake::~snake()
{}

arcade::IGameModule::~IGameModule()
{}

arcade::GameObject arcade::snake::findPlayerGameObject(std::vector<GameObject> go)
{
    std::vector<GameObject>::iterator g;

    for (g = go.begin(); g != go.end();  g++) {
        if (g->type == GameObject::PLAYER)
            return *g;
    }
    return *g;
}

arcade::GameObject arcade::snake::findBonusGameObject(std::vector<GameObject> go)
{
    std::vector<GameObject>::iterator g;

    for (g = go.begin(); g != go.end();  g++) {
        if (g->type == GameObject::BONUS)
            return *g;
    }
    return *g;
}

std::vector<arcade::GameObject> arcade::snake::getPlayer2()
{
    std::vector<arcade::GameObject> tmp;
    std::vector<GameObject>::iterator g;
    int i = 0;

    for (g = _SnakeGO.begin(); g != _SnakeGO.end(); g++) {
        if (g->type == GameObject::PLAYER2) {
            tmp[i] = *g;
            i++;
        }
    }
    return tmp;
}

bool arcade::snake::WallCollision(arcade::GameObject Player)
{
    std::vector<GameObject>::iterator g;
    int i = 0;

    for (g = _SnakeGO.begin(); g != _SnakeGO.end(); g++) {
            if (g->type == GameObject::WALL) {
                if (Player.pos.x == g->pos.x && Player.pos.y == g->pos.y)
                    return true;
        }
    }
    return false;
}

void arcade::snake::updateGame(const arcade::event &evt)
{
    std::vector<GameObject>::iterator g;
    arcade::GameObject Bonus = findBonusGameObject(_SnakeGO);
    arcade::GameObject Player = findPlayerGameObject(_SnakeGO);

    switch (evt) {
        case Right:
            _SnakeEvent = Right;
            break;
        case Left:
            _SnakeEvent = Left;
            break;
        case Up:
            _SnakeEvent = Up;
            break;
        case Down:
            _SnakeEvent = Down;
        case Quit:
            break;
        default: break;
    }
    switch(_SnakeEvent) {
        case Right:
            for (g = _SnakeGO.begin(); g != _SnakeGO.end();  g++) {
                if (g->type == GameObject::PLAYER)
                    g->pos.x += 1;
            }
            break;
        case Left:
            for (g = _SnakeGO.begin(); g != _SnakeGO.end();  g++) {
                if (g->type == GameObject::PLAYER)
                    g->pos.x -= 1;
            }
            break;
        case Up:
            for (g = _SnakeGO.begin(); g != _SnakeGO.end();  g++) {
                if (g->type == GameObject::PLAYER)
                    g->pos.y -= 1;
            }
            break;
        case Down:
            for (g = _SnakeGO.begin(); g != _SnakeGO.end();  g++) {
                if (g->type == GameObject::PLAYER)
                    g->pos.y += 1;
            }
            break;
        default: break;
    }

    //if (WallCollision(Player))
        //exit(84);
    if ((Player.pos.x >= Bonus.pos.x && Player.pos.x <= Bonus.pos.x) && (Player.pos.y >= Bonus.pos.y && Player.pos.y <= Bonus.pos.y)) {
        for (g = _SnakeGO.begin(); g != _SnakeGO.end();  g++) {
            if (g->type == GameObject::BONUS) {
                g->pos.y = rand() % 20;
                g->pos.x = rand() % 20;
                if (WallCollision(*g)) {
                    g->pos.x = Player.pos.x - 1;
                    g->pos.y = Player .pos.y - 1;
                }
            }
        }
    }
}

const std::vector<arcade::GameObject> &arcade::snake::getGameObjects(void) const
{
    return _SnakeGO;
}
