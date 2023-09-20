#pragma once
#include <string>
class Player{
    public:
        Player();
        Player(const std::string name);
        const unsigned int player_name()const;
    private:
        std::string name;
        const unsigned int score;
};
