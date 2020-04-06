/*
** EPITECH PROJECT, 2022
** OOP_arcade_2019
** File description:
** Created by Zebens,
*/

#include "LibLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

template<typename T>
inline
arcade::LibLoader<T>::LibLoader(const std::string &path) :
_handler(nullptr), create(nullptr), _p(path)
//try {
{
    _handler = dlopen(path.c_str(), RTLD_LAZY);
    if (_handler == nullptr) {
        std::cerr << dlerror() << std::endl;
        // throw
    }
    *(void **)(&create) = dlsym(_handler, "create");
} // catch

template<typename T>
inline
arcade::LibLoader<T>::~LibLoader()
{
    dlclose(_handler);
}

template<typename T>
inline
T arcade::LibLoader<T>::load()
{
    return create();
}

template class arcade::LibLoader<arcade::IDisplayModule *>;
template class arcade::LibLoader<arcade::IGameModule *>;
