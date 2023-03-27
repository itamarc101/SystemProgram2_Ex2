#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Game {
        private:
        Player p1;
        Player p2;

        public:
        Game(Player p1, Player p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}
#endif 