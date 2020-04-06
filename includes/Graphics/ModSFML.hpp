/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLclass.hpp
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../IDisplayModule.hpp"
#include <SFML/Audio.hpp>
#include <string>
#include "../color.hpp"
#include <vector>
#include "../Errors/ArcadeError.hpp"

#ifndef MOD_SFML_HPP_
#define MOD_SFML_HPP_

namespace arcade {
    class SFMLclass : public arcade::IDisplayModule {
        private:
            sf::RenderWindow _Window;
            sf::Sprite _BackgroundSprite;
            sf::Texture _BackgroundTexture;
            sf::Sprite _CursorSprite;
            sf::Texture _CursorTexture;
            sf::Font _Font;
            int _CharacterBigSize;
            int _nbGames;
            int _nbLibs;
            std::string _LibSelected;
            std::string _GameSelected;
            int cursor_posX;
            int cursor_posY;
            int current_game;
            int current_lib;
            bool left_side;

            sf::RectangleShape _Player;
            sf::RectangleShape _Bonus;
            sf::RectangleShape _Wall;

            bool _PopApple;
            sf::Event _event;
            arcade::event _ev;
            std::string _Game_Selected;

            sf::Sprite _SnakeHead;
            sf::Sprite _Apple;
            sf::Sprite _BackgroundSnake;
            std::vector<sf::Texture> _Textures;
            
            int _Score;
            
        protected:
        public:
            SFMLclass();
            ~SFMLclass() final;
        void drawPlayer(const vector2<unsigned> &) final;
        void drawPlayer2(const vector2<unsigned> &) final;
        void drawPlayerHit(const vector2<unsigned>&) final;
        void drawWall(const arcade::vector2<unsigned> &) final;
        void drawBonus(const arcade::vector2<unsigned> &) final;
        void drawBonus2(const arcade::vector2<unsigned> &) final;
        void drawEnemy(const arcade::vector2<unsigned> &) final;
        void drawEnemy2(const arcade::vector2<unsigned> &) final;
        void drawGameObjects(const std::vector<GameObject> &go) final;
        void drawMenu(const std::vector<std::string> &gamename, const std::vector<std::string> &display) final;
        void drawEnd() final;
        event getEvent(void) final;
        const std::string &getName() const final;

        void refresh(void) final;
        void drawText(const std::string &data, const vector2<unsigned> &pos) final;
        void display() final;
        
        // personals fctn //
        void move_cursor(std::vector<std::string>, std::vector<std::string>);
        void drawLittleText(const vector2<unsigned> pos, const std::string &data);
};
}

#endif