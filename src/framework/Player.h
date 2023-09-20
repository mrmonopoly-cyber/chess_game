#pragma once
/*
 * Author : Alberto Damo
 * Date : 2023-09-21
 */
#include <string>
class Player{
    public:
        Player();
        Player(const std::string name);
        const unsigned int player_name()const;
    private:
        std::string name;
};
