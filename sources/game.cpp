#include "game.hpp"
#include "player.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player p1, Player p2) : p1(p1), p2(p2) {}
    void Game::playAll() { }
    void Game::playTurn() { }
    void Game::printLastTurn() { }
    void Game::printLog() {}
    void Game::printStats() {}
    void Game::printWiner() {}
}