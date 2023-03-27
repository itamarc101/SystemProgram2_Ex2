#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Player 
    {
        private:
            string name;
        public:
            Player(string name);
            int stacksize();
            int cardesTaken();
    };
}
#endif