/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** event.hpp
*/

#ifndef OOP_ARCADE_2019_EVENT_HPP
#define OOP_ARCADE_2019_EVENT_HPP

namespace arcade
{
    typedef enum arcade_events
    {
        InvalidKey = -1,
        Left, Right, Up, Down,
        Action1, Action2,
        Pause, Restart, Menu, Quit,
        SwitchGraphic, SwitchGame, Nothing
    } event;
}
#endif //OOP_ARCADE_2019_EVENT_HPP
