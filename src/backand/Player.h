#ifndef _PLAYER_
#define _PLAYER_
#include <string>
class Player{
    public:
        const unsigned int player_name()const;
        Player() = delete;
        Player(const std::string name);
    private:
        const std::string name;
        const unsigned int score;
};
#endif //!_PLAYER_
