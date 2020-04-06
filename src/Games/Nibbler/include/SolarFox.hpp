/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Solar Fox
*/

#include "../../../../includes/GameObject.hpp"
#include "../../../../includes/event.hpp"
#include <list>
#include "../../../../includes/IGameModule.hpp"
#include "../../../../includes/IDisplayModule.hpp"
#include "../../../../includes/vector2.hpp"
#include "../../../../includes/Map.hpp"

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

namespace arcade {
    class solarfox : public IGameModule {
        private:
            std::vector<GameObject> _SolarFoxGO;
            arcade::event _SFEvent;
        protected:
        public:
            solarfox();
            ~solarfox();
            void setMap();
            void updateGame(const event &evt);
            const std::vector<GameObject> &getGameObjects(void) const;
            void init(void); // ctor
            void destroy(void); // dtor
            // FIND //
            GameObject findPlayerGameObject(std::vector<GameObject>);
            GameObject findBonusGameObject(std::vector<GameObject>);
            arcade::solarfox &operator+= (int);
            std::vector<GameObject> getPlayer2();
            bool WallCollision(arcade::GameObject);
    };
}

#endif