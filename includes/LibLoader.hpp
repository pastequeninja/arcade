/*
** EPITECH PROJECT, 2022
** OOP_arcade_2019
** File description:
** Created by Zebens,
*/

#ifndef __LOADFILES__HPP__
#define __LOADFILES__HPP__

#include <string>
#include <dlfcn.h>

namespace arcade
{
    template<typename T>
    class LibLoader
    {
    public:
        explicit LibLoader(const std::string &path);
        ~LibLoader();

        T load();

    private:
        void *_handler;
        T (*create)();
        const std::string _p;
    };
}

#endif
