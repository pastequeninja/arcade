/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** libParser.hpp
*/

#ifndef OOP_ARCADE_2019_LIBPARSER_HPP
#define OOP_ARCADE_2019_LIBPARSER_HPP

#include <string>
#include <filesystem>

namespace arcade
{
    class LibParser
    {
    public:
//        LibParser(const std::string &glp);
        static std::vector<std::string> collectLibs(const std::string &glP);
        static std::vector<std::string> collectLibs();
//        const std::vector<std::string> &getGamesPaths() const noexcept;
//        const std::vector<std::string> &getGLPaths() const noexcept;

    private:
//        std::vector<std::string> collectLibs(const std::string &glP);
//        std::vector<std::string> collectLibs();

        std::vector<std::string> _games, _gl;
        std::filesystem::path _paramLib;
    };
}

#endif //OOP_ARCADE_2019_LIBPARSER_HPP
