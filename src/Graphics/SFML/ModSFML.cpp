/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#include "../../../includes/Graphics/ModSFML.hpp"
#include "../../../includes/event.hpp"
#include <string.h>
#include <iostream>
#include "../../../includes/color.hpp"
#include "../../../includes/Errors/ArcadeError.hpp"

extern "C" {
    arcade::SFMLclass *create()
    {
        return (new arcade::SFMLclass());
    }
}

arcade::SFMLclass::SFMLclass()
{
    char *font = strdup("medias/Bubbleboddy-ExtraLightTrial.ttf");
    try {
        if (!_Font.loadFromFile(font))
            throw ArcadeError("sfmlClass", "Font not found");
        if (!_CursorTexture.loadFromFile("medias/arrow.png"))
            throw ArcadeError("sfmlClass", "Cursor sprite not found");
    } catch (arcade::ArcadeError &e) {
        throw e;
    } 
    _CursorSprite.setTexture(_CursorTexture);
    _CharacterBigSize = 40;
    _Player.setSize(sf::Vector2f(20, 20));
    _Player.setFillColor(sf::Color::White);
    _Bonus.setSize(sf::Vector2f(10, 10));
    _Bonus.setFillColor(sf::Color::White);

    _Wall.setFillColor(sf::Color::Black);
    _Wall.setOutlineThickness(10);
    _Wall.setOutlineColor(sf::Color(250, 150, 100));

    _Window.create(sf::VideoMode(800, 800), "ARCADE");
  
    _Score = 0;
    cursor_posX = 50;
    cursor_posY = 210;
    current_game = 0;
    current_lib = 0;
    left_side = true;
}

arcade::SFMLclass::~SFMLclass()
{
    _Window.close();
}

void arcade::SFMLclass::drawPlayer(const arcade::vector2<unsigned> &pos)
{
    _Player.setPosition(pos.x, pos.y);
    _Window.draw(_Player);
}

void arcade::SFMLclass::drawPlayer2(const arcade::vector2<unsigned> &pos)
{
    (void)pos;
    _Player.setPosition(pos.x, pos.y);
    _Window.draw(_Player);
}

void arcade::SFMLclass::drawPlayerHit(const arcade::vector2<unsigned> &pos)
{
    (void)pos;
    _Player.setPosition(pos.x, pos.y);
    _Window.draw(_Player);
}

void arcade::SFMLclass::drawWall(const arcade::vector2<unsigned> &pos)
{
    _Wall.setPosition(pos.x, pos.y);
    _Window.draw(_Wall);
}

void arcade::SFMLclass::drawBonus(const arcade::vector2<unsigned> &pos)
{
    _Bonus.setPosition(pos.x * 30, pos.y * 30);
    _Window.draw(_Bonus);
}

void arcade::SFMLclass::drawBonus2(const arcade::vector2<unsigned> &pos)
{
    (void)pos;
    _Bonus.setPosition(pos.x * 30, pos.y * 30);
    _Window.draw(_Bonus);
}

void arcade::SFMLclass::drawEnemy(const arcade::vector2<unsigned> &pos)
{
    (void)pos;
}

void arcade::SFMLclass::drawEnemy2(const arcade::vector2<unsigned> &pos)
{
    (void)pos;
}

arcade::event arcade::SFMLclass::getEvent()
{
    while (_Window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            return Quit;
        else if (_event.type == sf::Event::KeyReleased) {
            switch (_event.key.code) {
                case sf::Keyboard::Up: return Up;
                case sf::Keyboard::Down: return Down;
                case sf::Keyboard::Left: return Left;
                case sf::Keyboard::Right: return Right;
                case sf::Keyboard::Space: return Action1;
                case sf::Keyboard::Return: return Action2;
                case sf::Keyboard::R: return Restart;
                case sf::Keyboard::P: return Pause;
                case sf::Keyboard::M: return Menu;
                case sf::Keyboard::Q: return Quit;
                case sf::Keyboard::L: return SwitchGraphic;
                case sf::Keyboard::G: return SwitchGame;
                default: return Nothing;
            }
        }
    }
    return Nothing;
}

void arcade::SFMLclass::refresh()
{
    _Window.clear();
}

void arcade::SFMLclass::display()
{
    _Window.display();
}

void arcade::SFMLclass::drawGameObjects(const std::vector<arcade::GameObject> &g)
{
    refresh();
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
    display();
}

const std::string &arcade::SFMLclass::getName() const
{
    return _LibSelected;
}


void print(std::vector<sf::Text> input)
{
    for (unsigned j = 0; j < input.size(); j++)
        std::cout << input[j].getString().toAnsiString() << " ";
}

void arcade::SFMLclass::drawText(const std::string &data, const vector2<unsigned> &pos)
{
    sf::Text tmp;

    tmp.setFont(_Font);
    tmp.setString(data);
    tmp.setPosition(pos.x, pos.y);
    tmp.setCharacterSize(_CharacterBigSize);
    tmp.setFillColor(sf::Color::White);
    _Window.draw(tmp);
}


void arcade::SFMLclass::drawLittleText(const vector2<unsigned> pos, const std::string &data)
{
    sf::Text tmp;

    tmp.setFont(_Font);
    tmp.setString(data);
    tmp.setPosition(pos.x, pos.y);
    tmp.setCharacterSize(25);
    tmp.setFillColor(sf::Color::White);
    _Window.draw(tmp);
}

void arcade::SFMLclass::move_cursor(std::vector<std::string> graph, std::vector<std::string> games)
{
    if (_event.key.code == sf::Keyboard::Right) {
        left_side = false;
        cursor_posX = 350;
        cursor_posY = 210;
        current_game = 0;
    }
    if (_event.key.code == sf::Keyboard::Left) {
        left_side = true;
        cursor_posX = 50;
        cursor_posY = 210;
        current_lib = 0;
    }
    if (left_side == false && _event.key.code == sf::Keyboard::Down && (current_game < _nbGames - 1)) {
        current_game++;
        (cursor_posY) += 40;
    }
    if (left_side == false && _event.key.code == sf::Keyboard::Up && (current_game != 0)) {
        current_game--;
        (cursor_posY) -= 40;
    }
    if (left_side == true && _event.key.code == sf::Keyboard::Down && (current_lib < _nbLibs - 1)) {
        current_lib++;
        (cursor_posY) += 40;
    }
    if (left_side == true && _event.key.code == sf::Keyboard::Up && (current_lib != 0)) {
        current_lib--;
        (cursor_posY) -= 40;
    }
    if (left_side == true && _event.key.code == sf::Keyboard::Return)
        _GameSelected = graph[current_lib];
    if (left_side == false && _event.key.code == sf::Keyboard::Return)
        _LibSelected = games[current_game];
}

void arcade::SFMLclass::drawMenu(const std::vector<std::string> &games, const std::vector<std::string> &libgraph)
{
    int tmpX = 30;
    int tmpY = 200;

    _nbGames = games.size();
    _nbLibs = libgraph.size();

    if (_event.key.code == sf::Keyboard::Up)
            _Window.close();
    drawText("MENU", vector2<unsigned>(340, 70));
    move_cursor(libgraph, games);
    for (__SIZE_TYPE__ j = 0; j < games.size(); ++j) {
        drawText(games[j], vector2<unsigned>(600, tmpY));
        tmpY += 40;
    }
    tmpY = 200;
    for (__SIZE_TYPE__ j = 0; j < libgraph.size(); ++j) {
        drawText(libgraph[j], vector2<unsigned>(100, tmpY));
        tmpY += 40;
    }
    tmpY = 200;
    drawLittleText(vector2<unsigned>(260, 370), "The selected game is : " + _GameSelected);
    drawLittleText(vector2<unsigned>(280, 400), "The selected lib is : " + _LibSelected);
    if (_LibSelected.size() != 0 && _GameSelected.size() != 0)
        drawText("PRESS SPACE TO START", vector2<unsigned int>(380, 540));
    _CursorSprite.setPosition(cursor_posX, cursor_posY);
    _CursorSprite.setScale(0.07f,0.07f);
    _Window.draw(_CursorSprite);
    _Window.display();
    _Window.clear();
}

void arcade::SFMLclass::drawEnd()
{}
