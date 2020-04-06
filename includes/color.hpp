/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** color.hpp
*/

#ifndef OOP_ARCADE_2019_COLOR_HPP
#define OOP_ARCADE_2019_COLOR_HPP

namespace arcade
{
    struct color
    {
        unsigned r, g, b;
        color()
        {
            r = 0;
            g = 0;
            b = 0;
        }
        color(unsigned c)
        {
            r = c;
            g = c;
            b = c;
        }
        color(unsigned pr, unsigned pg, unsigned pb)
        {
            r = pr;
            g = pg;
            b = pb;
        }
    };
}

#endif //OOP_ARCADE_2019_COLOR_HPP
