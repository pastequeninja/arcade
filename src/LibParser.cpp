/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibParser.cpp
*/

#include "LibParser.hpp"
#include "ArcadeError.hpp"
#include "InvalidLibrary.hpp"
#include "DirectoryError.hpp"
#include <fstream>
#include <dirent.h>

std::vector<std::string> arcade::LibParser::collectLibs(const std::string &glP) // read ./lib
{
    std::fstream fs(glP);
    if (fs.is_open() == false)
        throw arcade::InvalidLibrary("LibParser", glP + " can't be used.");
    fs.close();
    DIR *dirp = opendir("./lib");
    if (!dirp)
        throw arcade::DirectoryError("LibParser", "Directory ./lib not found or can't be opened.");
    struct dirent *d = readdir(dirp);
    std::vector<std::string> res;
    res.push_back(glP);
    std::filesystem::path glPath(glP);

    while (d) {
        std::string dname(d->d_name);
        if (dname.size() < 14 || dname.substr(0, 11) != "lib_arcade_" || dname.substr(dname.size()-3) != ".so");
        else {
            if (!std::filesystem::equivalent(std::filesystem::path("./lib/" + dname), glPath))
                res.push_back(dname);
        }
        d = readdir(dirp);
    }
    closedir(dirp);
    return res;
}

std::vector<std::string> arcade::LibParser::collectLibs() // read ./games
{
    DIR *dirp = opendir("./games");
    if (!dirp)
        throw arcade::DirectoryError("LibParser", "Directory ./games not found or can't be opened.");
    struct dirent *d = readdir(dirp);
    std::vector<std::string> res;

    while (d) {
        std::string dname(d->d_name);
        if (dname.size() < 14 || dname.substr(0, 11) != "lib_arcade_" || dname.substr(dname.size()-3) != ".so");
        else
            res.push_back(dname);
        d = readdir(dirp);
    }
    closedir(dirp);
    return res;
}
