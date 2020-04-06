/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ArcadeError.hpp
*/

#ifndef OOP_ARCADE_2019_ARCADEERROR_HPP
#define OOP_ARCADE_2019_ARCADEERROR_HPP

#include <exception>
#include <string>

namespace arcade
{
    class ArcadeError : public std::exception
    {
    public:
        ArcadeError(const std::string &where, const std::string &what);
        const std::string &where() const noexcept;
        const char *what() const noexcept final;

    protected:
        const std::string _location;
        const std::string _message;
    };
}

#endif //OOP_ARCADE_2019_ARCADEERROR_HPP
