/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** vector2.hpp
*/

#ifndef OOP_ARCADE_2019_VECTOR2_HPP
#define OOP_ARCADE_2019_VECTOR2_HPP

#include <iostream>

namespace arcade
{
    template<typename T = unsigned>
    struct vector2
    {
        T x;
        T y;

        vector2<T>()
        {
            x = 0;
            y = 0;
        }
        vector2<T>(const T &val)
        {
            x = val;
            y = val;
        }
        vector2<T>(const T &val1, const T &val2)
        {
            x = val1;
            y = val2;
        }
    };
}
#endif //OOP_ARCADE_2019_VECTOR2_HPP
