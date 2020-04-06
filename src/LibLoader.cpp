/*
** EPITECH PROJECT, 2022
** OOP_arcade_2019
** File description:
** Created by Zebens,
*/

#include "LibLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "ArcadeError.hpp"

template<typename T>
inline
arcade::LibLoader<T>::LibLoader(const std::string &path)
try : _handler(nullptr), create(nullptr), _p(path)
{
//{
    _handler = dlopen(path.c_str(), RTLD_LAZY);
    if (_handler == nullptr) {
        throw ArcadeError("LibLoader", dlerror());
    }
    if ((*(void **)(&create) = dlsym(_handler, "create")) == NULL)
        throw ArcadeError("LibLoader", dlerror());
} catch (const arcade::ArcadeError &e) {
    throw e;
}

template<typename T>
inline
arcade::LibLoader<T>::~LibLoader()
{
//    if (_handler == nullptr || dlclose(_handler) != 0)
//        std::cerr << "Error dlclose " << _handler << std::endl;
}

template<typename T>
inline
T arcade::LibLoader<T>::load()
{
    return create();
}

template class arcade::LibLoader<arcade::IDisplayModule *>;
template class arcade::LibLoader<arcade::IGameModule *>;
