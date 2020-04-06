/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake game
*/

#include "../../../../includes/GameObject.hpp"
#include "../../../../includes/event.hpp"
#include <list>
#include "../../../../includes/IGameModule.hpp"
#include "../../../../includes/IDisplayModule.hpp"
#include "../../../../includes/vector2.hpp"
#include "../../../../includes/Map.hpp"

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

//extern "C" arcade::IGameModule *create();

namespace arcade {
    class snake : public IGameModule {
        private:
            std::vector<GameObject> _SnakeGO;
            arcade::event _SnakeEvent;
            int _Snake_Head;
            
        protected:
        public:
            snake();
            ~snake();
            void setMap();
            void updateGame(const event &evt);
            const std::vector<GameObject> &getGameObjects(void) const;
            void init(void); // ctor
            void destroy(void); // dtor
            // FIND //
            GameObject findPlayerGameObject(std::vector<GameObject>);
            GameObject findBonusGameObject(std::vector<GameObject>);
            arcade::snake &operator+= (int);
            std::vector<GameObject> getPlayer2();
            bool WallCollision(arcade::GameObject);
    };
}

#endif