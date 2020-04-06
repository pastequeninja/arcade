/*
** EPITECH PROJECT, 2020
** CPP
** File description:
** main.cpp
*/

#include "includes/IDisplayModule.hpp"
#include <dlfcn.h>
#include <iostream>
#include "includes/event.hpp"
#include <memory>
#include "src/Games/Nibbler/src/Snake.cpp"
#include "includes/IGameModule.hpp"

arcade::IDisplayModule *getSDLModule()
{
    void *handler = dlopen("./lib/lib_arcade_sdl.so", RTLD_LAZY);

    if (handler == nullptr)
        return nullptr;
    arcade::IDisplayModule *(*func_ptr)();
    *(void **)(&func_ptr) = dlsym(handler, "create");
    arcade::IDisplayModule *ptrModule(func_ptr());
//    dlclose(handler);
//    ptrModule->drawMenu();
//    ptrModule->drawObject();
    return ptrModule;    
}

arcade::IDisplayModule *getNcursesModule()
{
    void *handler = dlopen("./lib_arcade_ncurses.so", RTLD_LAZY);

    if (handler == nullptr) {
        std::cout << dlerror() << std::endl;
        return nullptr;
    }
    arcade::IDisplayModule *(*func_ptr)();
    *(void **)(&func_ptr) = dlsym(handler, "create");
    arcade::IDisplayModule *ptrModule(func_ptr());
//    dlclose(handler);
//    ptrModule->drawMenu();
//    ptrModule->drawObject();
    return ptrModule;
}

arcade::IGameModule *getSnakeModule()
{
    void *handler = dlopen("./lib_arcade_nibbler.so", RTLD_LAZY);

    if (handler == nullptr) {
        std::cout << "OVER" << std::endl << dlerror() << std::endl;
        return nullptr;
    }
    arcade::IGameModule *(*func_ptr)();
    *(void **)(&func_ptr) = dlsym(handler, "create");
    arcade::IGameModule *ptrModule(func_ptr());
//    dlclose(handler);
//    ptrModule->drawMenu();
//    ptrModule->drawObject();
    return ptrModule;
}

arcade::IDisplayModule * getSFMLModule()
{
    void *handler = dlopen("./sfml.so", RTLD_LAZY);

    if (handler == nullptr) {
        std::cout << dlerror() << std::endl;
        return nullptr;
    }
    arcade::IDisplayModule *(*func_ptr)();
    if ((*(void **)(&func_ptr) = dlsym(handler, "create")) == NULL)
        std::cout << dlerror() << std::endl;
    arcade::IDisplayModule *ptrModule(func_ptr());
//    dlclose(handler);
//    ptrModule->drawMenu();
//    ptrModule->drawObject();
    return ptrModule;
}

void closeModuleHandler(void *handler)
{
    dlclose(handler);
}

int main(void)
{
    arcade::IDisplayModule *ncurses = getNcursesModule();
    //arcade::IDisplayModule *SDL = getSDLModule();
    arcade::IGameModule *Snake = getSnakeModule();

     while (true) {
        arcade::event evt = ncurses->getEvent();
        switch (evt) {
            case arcade::event::Quit:
                return 0;
            default:
                break;
        }
         Snake->updateGame(evt);
         ncurses->drawGameObjects(Snake->getGameObjects());
     }
    return 0;
}
